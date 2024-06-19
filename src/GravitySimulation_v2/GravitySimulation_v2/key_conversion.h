#ifndef KEY_CONVERSION_H
#define KEY_CONVERSION_H

#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <unordered_map>

std::string key_to_string(sf::Keyboard::Key key) {
    static std::unordered_map<sf::Keyboard::Key, std::string> key_map = {
        {sf::Keyboard::A, "A"},
        {sf::Keyboard::B, "B"},
        {sf::Keyboard::C, "C"},
        {sf::Keyboard::D, "D"},
        {sf::Keyboard::E, "E"},
        {sf::Keyboard::F, "F"},
        {sf::Keyboard::G, "G"},
        {sf::Keyboard::H, "H"},
        {sf::Keyboard::I, "I"},
        {sf::Keyboard::J, "J"},
        {sf::Keyboard::K, "K"},
        {sf::Keyboard::L, "L"},
        {sf::Keyboard::M, "M"},
        {sf::Keyboard::N, "N"},
        {sf::Keyboard::O, "O"},
        {sf::Keyboard::P, "P"},
        {sf::Keyboard::Q, "Q"},
        {sf::Keyboard::R, "R"},
        {sf::Keyboard::S, "S"},
        {sf::Keyboard::T, "T"},
        {sf::Keyboard::U, "U"},
        {sf::Keyboard::V, "V"},
        {sf::Keyboard::W, "W"},
        {sf::Keyboard::X, "X"},
        {sf::Keyboard::Y, "Y"},
        {sf::Keyboard::Z, "Z"},
        {sf::Keyboard::Num0, "0"},
        {sf::Keyboard::Num1, "1"},
        {sf::Keyboard::Num2, "2"},
        {sf::Keyboard::Num3, "3"},
        {sf::Keyboard::Num4, "4"},
        {sf::Keyboard::Num5, "5"},
        {sf::Keyboard::Num6, "6"},
        {sf::Keyboard::Num7, "7"},
        {sf::Keyboard::Num8, "8"},
        {sf::Keyboard::Num9, "9"},
        {sf::Keyboard::Escape, "ESCAPE"},
        {sf::Keyboard::LControl, "LEFT CONTROL"},
        {sf::Keyboard::LShift, "LEFT SHIFT"},
        {sf::Keyboard::LAlt, "LEFT ALT"},
        {sf::Keyboard::LSystem, "LEFT SYSTEM"},
        {sf::Keyboard::RControl, "RIGHT CONTROL"},
        {sf::Keyboard::RShift, "RIGHT SHIFT"},
        {sf::Keyboard::RAlt, "RIGHT ALT"},
        {sf::Keyboard::RSystem, "RIGHT SYSTEM"},
        {sf::Keyboard::Menu, "MENU"},
        {sf::Keyboard::LBracket, "["},
        {sf::Keyboard::RBracket, "]"},
        {sf::Keyboard::SemiColon, ";"},
        {sf::Keyboard::Comma, ","},
        {sf::Keyboard::Period, "."},
        {sf::Keyboard::Quote, "'"},
        {sf::Keyboard::Slash, "/"},
        {sf::Keyboard::BackSlash, "\\"},
        {sf::Keyboard::Tilde, "`"},
        {sf::Keyboard::Equal, "="},
        {sf::Keyboard::Dash, "-"},
        {sf::Keyboard::Space, "SPACE"},
        {sf::Keyboard::Return, "RETURN"},
        {sf::Keyboard::BackSpace, "BACKSPACE"},
        {sf::Keyboard::Tab, "TAB"},
        {sf::Keyboard::PageUp, "PAGE UP"},
        {sf::Keyboard::PageDown, "PAGE DOWN"},
        {sf::Keyboard::End, "END"},
        {sf::Keyboard::Home, "HOME"},
        {sf::Keyboard::Insert, "INSERT"},
        {sf::Keyboard::Delete, "DELETE"},
        {sf::Keyboard::Add, "ADD"},
        {sf::Keyboard::Subtract, "SUBTRACT"},
        {sf::Keyboard::Multiply, "MULTIPLY"},
        {sf::Keyboard::Divide, "DIVIDE"},
        {sf::Keyboard::Left, "LEFT"},
        {sf::Keyboard::Right, "RIGHT"},
        {sf::Keyboard::Up, "UP"},
        {sf::Keyboard::Down, "DOWN"},
        {sf::Keyboard::Numpad0, "NUMPAD 0"},
        {sf::Keyboard::Numpad1, "NUMPAD 1"},
        {sf::Keyboard::Numpad2, "NUMPAD 2"},
        {sf::Keyboard::Numpad3, "NUMPAD 3"},
        {sf::Keyboard::Numpad4, "NUMPAD 4"},
        {sf::Keyboard::Numpad5, "NUMPAD 5"},
        {sf::Keyboard::Numpad6, "NUMPAD 6"},
        {sf::Keyboard::Numpad7, "NUMPAD 7"},
        {sf::Keyboard::Numpad8, "NUMPAD 8"},
        {sf::Keyboard::Numpad9, "NUMPAD 9"},
        {sf::Keyboard::F1, "F1"},
        {sf::Keyboard::F2, "F2"},
        {sf::Keyboard::F3, "F3"},
        {sf::Keyboard::F4, "F4"},
        {sf::Keyboard::F5, "F5"},
        {sf::Keyboard::F6, "F6"},
        {sf::Keyboard::F7, "F7"},
        {sf::Keyboard::F8, "F8"},
        {sf::Keyboard::F9, "F9"},
        {sf::Keyboard::F10, "F10"},
        {sf::Keyboard::F11, "F11"},
        {sf::Keyboard::F12, "F12"},
        {sf::Keyboard::F13, "F13"},
        {sf::Keyboard::F14, "F14"},
        {sf::Keyboard::F15, "F15"},
        {sf::Keyboard::Pause, "PAUSE"},
    };

    auto it = key_map.find(key);
    if (it != key_map.end()) {
        return it->second;
    }
    else {
        return "UNKNOWN";
    }
}


#endif
