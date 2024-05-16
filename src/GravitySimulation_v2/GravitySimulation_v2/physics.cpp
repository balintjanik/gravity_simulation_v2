#include <vector>

#include "settings.h"
#include "particle.h"
#include "utils.h"
#include "grid.h"

using namespace std;

void update_gravity(vector<Particle>& particles)
{
    for (int i = 0; i < N; i++)
    {
        Particle& p_1 = particles[i];
        float all_force = 0.0f;

        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;

            // Calculate distance and angle
            Particle& p_2 = particles[j];
            float angle = atan2(p_1.position.y - p_2.position.y, p_1.position.x - p_2.position.x);
            float distance = v2f_distance(p_1.position, p_2.position);
            
            // Calculate gravitational force
            float g = 1;
            float force = (g * p_1.mass * p_2.mass) / pow(distance, 2);

            // Dampen angular velocity for close particles
            float min_distance = p_1.radius + p_2.radius + COLLISION_THRESHOLD;
            if (distance < min_distance + DAMPING_DIST)
                angle = angle * (1 - DAMPING_COEFF);

            // Update velocity
            p_1.velocity.x -= force * cos(angle);
            p_1.velocity.y -= force * sin(angle);
            all_force += force;
        }

        // Update color based on amount of gravitational force
        sf::Color updated_color = map_forces_to_color(all_force);
        p_1.color = updated_color;

        // Bounce back from borders if enabled
        if (HAS_BORDERS) {
            if (p_1.position.x > WIDTH || p_1.position.x < 0) p_1.velocity.x = -p_1.velocity.x;
            if (p_1.position.y > HEIGHT || p_1.position.y < 0) p_1.velocity.y = -p_1.velocity.y;
        }
    }
}

void check_cells_collision(vector<Particle>& particles, Cell& cell_1, Cell& cell_2)
{
    int idx_1, idx_2;

    for (auto it1 = cell_1.particle_indices.begin(); it1 != cell_1.particle_indices.end(); ++it1)
    {
        idx_1 = get_idx_by_id(particles, *it1);
        if (idx_1 < 0)
            continue;

        Particle& p_1 = particles[idx_1];

        for (auto it2 = cell_2.particle_indices.begin(); it2 != cell_2.particle_indices.end(); ++it2)
        {
            idx_2 = get_idx_by_id(particles, *it2);
            if (idx_2 < 0)
                continue;

            Particle& p_2 = particles[idx_2];

            if (p_1.id == p_2.id)
                continue;

            // Calculate distances
            float dx = p_2.position.x - p_1.position.x;
            float dy = p_2.position.y - p_1.position.y;
            float distance = v2f_distance(p_1.position, p_2.position);
            float min_distance = p_1.radius + p_2.radius + COLLISION_THRESHOLD;

            // Check collision
            if (distance < min_distance)
            {
                if (HAS_OVERLAPCHECK)
                {
                    float displacement_x = (dx / distance) * (min_distance - distance) / 2.0f;
                    float displacement_y = (dy / distance) * (min_distance - distance) / 2.0f;

                    // Update position directly to avoid overlaps
                    p_1.position.x -= displacement_x;
                    p_1.position.y -= displacement_y;
                    p_2.position.x += displacement_x;
                    p_2.position.y += displacement_y;
                }

                if (HAS_BOUNCEOFF)
                {
                    // Calculate relative velocity
                    float relative_velocity_x = p_2.velocity.x - p_1.velocity.x;
                    float relative_velocity_y = p_2.velocity.y - p_1.velocity.y;

                    // Calculate normal vector
                    float normal_x = dx / distance;
                    float normal_y = dy / distance;

                    // Calculate impulse (change in velocity)
                    float impulse = 1.0f * (relative_velocity_x * normal_x + relative_velocity_y * normal_y) / (p_1.mass + p_2.mass);

                    // Update velocities based on impulse (conservation of momentum)
                    p_1.velocity.x += impulse * normal_x * p_2.mass;
                    p_1.velocity.y += impulse * normal_y * p_2.mass;
                    p_2.velocity.x -= impulse * normal_x * p_1.mass;
                    p_2.velocity.y -= impulse * normal_y * p_1.mass;
                }
            }
            // Dampen velocity of close particles to avoid too fast spinning of planets
            else if (distance < min_distance + DAMPING_DIST && p_1.id < p_2.id)
            {
                p_1.velocity *= (1 - DAMPING_COEFF);
            }
        }
    }
}

void update_collisions(vector<Particle>& particles, Grid& collision_grid)
{
    for (int x = 1; x < collision_grid.width - 1; x++)
    {
        for (int y = 1; y < collision_grid.height - 1; y++)
        {
            auto& current_cell = collision_grid.get(x, y);
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    auto& other_cell = collision_grid.get(x + dx, y + dy);
                    check_cells_collision(particles, current_cell, other_cell);
                }
            }
        }
    }
}

void update_trails(vector<Particle>& particles)
{
    for (auto& p : particles)
    {
        if (p.trail.size() > TRAIL_SIZE)
            p.trail.pop_front();
        sf::Vector2f old_position(p.position.x, p.position.y);
        p.trail.push_back(old_position);
    }
}

void update_positions(vector<Particle> &particles, Grid& collision_grid)
{
    // Calculate collisions
    update_collisions(particles, collision_grid);

    // Calculate gravitational forces
    update_gravity(particles);

    // Update trails
    if (HAS_TRAIL)
        update_trails(particles);

    // Calculate new positions
    for (auto& p : particles)
    {
        p.old_position = p.position;
        p.position += p.velocity * TIMESTEP;

        collision_grid.update_particle_cell(p);
    }
}