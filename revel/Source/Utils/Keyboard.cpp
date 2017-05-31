#include "Keyboard.h"

namespace rvl {
    uint8 Keyboard::A           = sf::Keyboard::A;
    uint8 Keyboard::B           = sf::Keyboard::B;
    uint8 Keyboard::C           = sf::Keyboard::C;
    uint8 Keyboard::D           = sf::Keyboard::D;
    uint8 Keyboard::E           = sf::Keyboard::E;
    uint8 Keyboard::F           = sf::Keyboard::F;
    uint8 Keyboard::G           = sf::Keyboard::G;
    uint8 Keyboard::H           = sf::Keyboard::H;
    uint8 Keyboard::I           = sf::Keyboard::I;
    uint8 Keyboard::J           = sf::Keyboard::J;
    uint8 Keyboard::K           = sf::Keyboard::K;
    uint8 Keyboard::L           = sf::Keyboard::L;
    uint8 Keyboard::M           = sf::Keyboard::M;
    uint8 Keyboard::N           = sf::Keyboard::N;
    uint8 Keyboard::O           = sf::Keyboard::O;
    uint8 Keyboard::P           = sf::Keyboard::P;
    uint8 Keyboard::Q           = sf::Keyboard::Q;
    uint8 Keyboard::R           = sf::Keyboard::R;
    uint8 Keyboard::S           = sf::Keyboard::S;
    uint8 Keyboard::T           = sf::Keyboard::T;
    uint8 Keyboard::U           = sf::Keyboard::U;
    uint8 Keyboard::V           = sf::Keyboard::V;
    uint8 Keyboard::W           = sf::Keyboard::W;
    uint8 Keyboard::X           = sf::Keyboard::X;
    uint8 Keyboard::Y           = sf::Keyboard::Y;
    uint8 Keyboard::Z           = sf::Keyboard::Z;
    uint8 Keyboard::Num0        = sf::Keyboard::Num0;
    uint8 Keyboard::Num1        = sf::Keyboard::Num1;
    uint8 Keyboard::Num2        = sf::Keyboard::Num2;
    uint8 Keyboard::Num3        = sf::Keyboard::Num3;
    uint8 Keyboard::Num4        = sf::Keyboard::Num4;
    uint8 Keyboard::Num5        = sf::Keyboard::Num5;
    uint8 Keyboard::Num6        = sf::Keyboard::Num6;
    uint8 Keyboard::Num7        = sf::Keyboard::Num7;
    uint8 Keyboard::Num8        = sf::Keyboard::Num8;
    uint8 Keyboard::Num9        = sf::Keyboard::Num9;
    uint8 Keyboard::Escape      = sf::Keyboard::Escape;
    uint8 Keyboard::LControl    = sf::Keyboard::LControl;
    uint8 Keyboard::LShift      = sf::Keyboard::LShift;
    uint8 Keyboard::LAlt        = sf::Keyboard::LAlt;
    uint8 Keyboard::LSystem     = sf::Keyboard::LSystem;
    uint8 Keyboard::RControl    = sf::Keyboard::RControl;
    uint8 Keyboard::RShift      = sf::Keyboard::RShift;
    uint8 Keyboard::RAlt        = sf::Keyboard::RAlt;
    uint8 Keyboard::RSystem     = sf::Keyboard::RSystem;
    uint8 Keyboard::RBracket    = sf::Keyboard::RBracket;
    uint8 Keyboard::LBracket    = sf::Keyboard::LBracket;
    uint8 Keyboard::Menu        = sf::Keyboard::Menu;
    uint8 Keyboard::SemiColon   = sf::Keyboard::SemiColon;
    uint8 Keyboard::Comma       = sf::Keyboard::Comma;
    uint8 Keyboard::Period      = sf::Keyboard::Period;
    uint8 Keyboard::Quote       = sf::Keyboard::Quote;
    uint8 Keyboard::Slash       = sf::Keyboard::Slash;
    uint8 Keyboard::BackSlash   = sf::Keyboard::BackSlash;
    uint8 Keyboard::Tilde       = sf::Keyboard::Tilde;
    uint8 Keyboard::Equal       = sf::Keyboard::Equal;
    uint8 Keyboard::Dash        = sf::Keyboard::Dash;
    uint8 Keyboard::Space       = sf::Keyboard::Space;
    uint8 Keyboard::Return      = sf::Keyboard::Space;
    uint8 Keyboard::BackSpace   = sf::Keyboard::BackSpace;
    uint8 Keyboard::Tab         = sf::Keyboard::Tab;
    uint8 Keyboard::PageUp      = sf::Keyboard::PageUp;
    uint8 Keyboard::PageDown    = sf::Keyboard::PageDown;
    uint8 Keyboard::End         = sf::Keyboard::End;
    uint8 Keyboard::Home        = sf::Keyboard::Home;
    uint8 Keyboard::Insert      = sf::Keyboard::Insert;
    uint8 Keyboard::Delete      = sf::Keyboard::Delete;
    uint8 Keyboard::Add         = sf::Keyboard::Add;
    uint8 Keyboard::Subtract    = sf::Keyboard::Subtract;
    uint8 Keyboard::Multiply    = sf::Keyboard::Multiply;
    uint8 Keyboard::Divide      = sf::Keyboard::Divide;
    uint8 Keyboard::Left        = sf::Keyboard::Left;
    uint8 Keyboard::Right       = sf::Keyboard::Right;
    uint8 Keyboard::Up          = sf::Keyboard::Up;
    uint8 Keyboard::Down        = sf::Keyboard::Down;
    uint8 Keyboard::Numpad0     = sf::Keyboard::Numpad0;
    uint8 Keyboard::Numpad1     = sf::Keyboard::Numpad1;
    uint8 Keyboard::Numpad2     = sf::Keyboard::Numpad2;
    uint8 Keyboard::Numpad3     = sf::Keyboard::Numpad3;
    uint8 Keyboard::Numpad4     = sf::Keyboard::Numpad4;
    uint8 Keyboard::Numpad5     = sf::Keyboard::Numpad5;
    uint8 Keyboard::Numpad6     = sf::Keyboard::Numpad6;
    uint8 Keyboard::Numpad7     = sf::Keyboard::Numpad7;
    uint8 Keyboard::Numpad8     = sf::Keyboard::Numpad8;
    uint8 Keyboard::Numpad9     = sf::Keyboard::Numpad9;
    uint8 Keyboard::F1          = sf::Keyboard::F1;
    uint8 Keyboard::F2          = sf::Keyboard::F2;
    uint8 Keyboard::F3          = sf::Keyboard::F3;
    uint8 Keyboard::F4          = sf::Keyboard::F4;
    uint8 Keyboard::F5          = sf::Keyboard::F5;
    uint8 Keyboard::F6          = sf::Keyboard::F6;
    uint8 Keyboard::F7          = sf::Keyboard::F7;
    uint8 Keyboard::F8          = sf::Keyboard::F8;
    uint8 Keyboard::F9          = sf::Keyboard::F9;
    uint8 Keyboard::F10         = sf::Keyboard::F10;
    uint8 Keyboard::F11         = sf::Keyboard::F11;
    uint8 Keyboard::F12         = sf::Keyboard::F12;
    uint8 Keyboard::F13         = sf::Keyboard::F13;
    uint8 Keyboard::F14         = sf::Keyboard::F14;
    uint8 Keyboard::F15         = sf::Keyboard::F15;

	bool Keyboard::IsKeyPressed(uint8 keycode) {
		return sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keycode));
	}

	void Keyboard::DoBind(lua_State * Lua) {
		luabridge::getGlobalNamespace(Lua)
			.beginNamespace("rvl")
				.beginClass<Keyboard>("Keyboard")
					.addConstructor<void(*)(void)>()
					.addStaticFunction("IsKeyPressed", &rvl::Keyboard::IsKeyPressed)
					.addStaticData("A",			&rvl::Keyboard::A,			false)
					.addStaticData("B",			&rvl::Keyboard::B,			false)
					.addStaticData("C",			&rvl::Keyboard::C,			false)
					.addStaticData("D",			&rvl::Keyboard::D,			false)
					.addStaticData("E",			&rvl::Keyboard::E,			false)
					.addStaticData("F",			&rvl::Keyboard::F,			false)
					.addStaticData("G",			&rvl::Keyboard::G,			false)
					.addStaticData("H",			&rvl::Keyboard::H,			false)
					.addStaticData("I",			&rvl::Keyboard::I,			false)
					.addStaticData("J",			&rvl::Keyboard::J,			false)
					.addStaticData("K",			&rvl::Keyboard::K,			false)
					.addStaticData("L",			&rvl::Keyboard::L,			false)
					.addStaticData("M",			&rvl::Keyboard::M,			false)
					.addStaticData("N",			&rvl::Keyboard::N,			false)
					.addStaticData("O",			&rvl::Keyboard::O,			false)
					.addStaticData("P",			&rvl::Keyboard::P,			false)
					.addStaticData("Q",			&rvl::Keyboard::Q,			false)
					.addStaticData("R",			&rvl::Keyboard::R,			false)
					.addStaticData("S",			&rvl::Keyboard::S,			false)
					.addStaticData("T",			&rvl::Keyboard::T,			false)
					.addStaticData("U",			&rvl::Keyboard::U,			false)
					.addStaticData("V",			&rvl::Keyboard::V,			false)
					.addStaticData("W",			&rvl::Keyboard::W,			false)
					.addStaticData("X",			&rvl::Keyboard::X,			false)
					.addStaticData("Y",			&rvl::Keyboard::Y,			false)
					.addStaticData("Z",			&rvl::Keyboard::Z,			false)
					.addStaticData("Num0",		&rvl::Keyboard::Num0,		false)
					.addStaticData("Num1",		&rvl::Keyboard::Num1,		false)
					.addStaticData("Num2",		&rvl::Keyboard::Num2,		false)
					.addStaticData("Num3",		&rvl::Keyboard::Num3,		false)
					.addStaticData("Num4",		&rvl::Keyboard::Num4,		false)
					.addStaticData("Num5",		&rvl::Keyboard::Num5,		false)
					.addStaticData("Num6",		&rvl::Keyboard::Num6,		false)
					.addStaticData("Num7",		&rvl::Keyboard::Num7,		false)
					.addStaticData("Num8",		&rvl::Keyboard::Num8,		false)
					.addStaticData("Num9",		&rvl::Keyboard::Num9,		false)
					.addStaticData("Escape",	&rvl::Keyboard::Escape,		false)
					.addStaticData("LControl",	&rvl::Keyboard::LControl,	false)
					.addStaticData("LShift",	&rvl::Keyboard::LShift,		false)
					.addStaticData("LAlt",		&rvl::Keyboard::LAlt,		false)
					.addStaticData("LSystem",	&rvl::Keyboard::LSystem,	false)
					.addStaticData("RControl",	&rvl::Keyboard::RControl,	false)
					.addStaticData("RShift",	&rvl::Keyboard::RShift,		false)
					.addStaticData("RAlt",		&rvl::Keyboard::RAlt,		false)
					.addStaticData("RSystem",	&rvl::Keyboard::RSystem,	false)
					.addStaticData("RBracket",	&rvl::Keyboard::RBracket,	false)
					.addStaticData("LBracket",	&rvl::Keyboard::LBracket,	false)
					.addStaticData("Menu",		&rvl::Keyboard::Menu,		false)
					.addStaticData("SemiColon", &rvl::Keyboard::SemiColon,	false)
					.addStaticData("Comma",		&rvl::Keyboard::Comma,		false)
					.addStaticData("Period",	&rvl::Keyboard::Period,		false)
					.addStaticData("Quote",		&rvl::Keyboard::Quote,		false)
					.addStaticData("Slash",		&rvl::Keyboard::Slash,		false)
					.addStaticData("BackSlash", &rvl::Keyboard::BackSlash,	false)
					.addStaticData("Tilde",		&rvl::Keyboard::Tilde,		false)
					.addStaticData("Equal",		&rvl::Keyboard::Equal,		false)
					.addStaticData("Dash",		&rvl::Keyboard::Dash,		false)
					.addStaticData("Space",		&rvl::Keyboard::Space,		false)
					.addStaticData("Return",	&rvl::Keyboard::Return,		false)
					.addStaticData("BackSpace", &rvl::Keyboard::BackSpace,	false)
					.addStaticData("Tab",		&rvl::Keyboard::Tab,		false)
					.addStaticData("PageUp",	&rvl::Keyboard::PageUp,		false)
					.addStaticData("PageDown",	&rvl::Keyboard::PageDown,	false)
					.addStaticData("End",		&rvl::Keyboard::End,		false)
					.addStaticData("Home",		&rvl::Keyboard::Home,		false)
					.addStaticData("Insert",	&rvl::Keyboard::Insert,		false)
					.addStaticData("Delete",	&rvl::Keyboard::Delete,		false)
					.addStaticData("Add",		&rvl::Keyboard::Add,		false)
					.addStaticData("Subtract",	&rvl::Keyboard::Subtract,	false)
					.addStaticData("Multiply",	&rvl::Keyboard::Multiply,	false)
					.addStaticData("Divide",	&rvl::Keyboard::Divide,		false)
					.addStaticData("Left",		&rvl::Keyboard::Left,		false)
					.addStaticData("Right",		&rvl::Keyboard::Right,		false)
					.addStaticData("Up",		&rvl::Keyboard::Up,			false)
					.addStaticData("Down",		&rvl::Keyboard::Down,		false)
					.addStaticData("Numpad0",	&rvl::Keyboard::Numpad0,	false)
					.addStaticData("Numpad1",	&rvl::Keyboard::Numpad1,	false)
					.addStaticData("Numpad2",	&rvl::Keyboard::Numpad2,	false)
					.addStaticData("Numpad3",	&rvl::Keyboard::Numpad3,	false)
					.addStaticData("Numpad4",	&rvl::Keyboard::Numpad4,	false)
					.addStaticData("Numpad5",	&rvl::Keyboard::Numpad5,	false)
					.addStaticData("Numpad6",	&rvl::Keyboard::Numpad6,	false)
					.addStaticData("Numpad7",	&rvl::Keyboard::Numpad7,	false)
					.addStaticData("Numpad8",	&rvl::Keyboard::Numpad8,	false)
					.addStaticData("Numpad9",	&rvl::Keyboard::Numpad9,	false)
					.addStaticData("F1",		&rvl::Keyboard::F1,			false)
					.addStaticData("F2",		&rvl::Keyboard::F2,			false)
					.addStaticData("F3",		&rvl::Keyboard::F3,			false)
					.addStaticData("F4",		&rvl::Keyboard::F4,			false)
					.addStaticData("F5",		&rvl::Keyboard::F5,			false)
					.addStaticData("F6",		&rvl::Keyboard::F6,			false)
					.addStaticData("F7",		&rvl::Keyboard::F7,			false)
					.addStaticData("F8",		&rvl::Keyboard::F8,			false)
					.addStaticData("F9",		&rvl::Keyboard::F9,			false)
					.addStaticData("F10",		&rvl::Keyboard::F10,		false)
					.addStaticData("F11",		&rvl::Keyboard::F11,		false)
					.addStaticData("F12",		&rvl::Keyboard::F12,		false)
					.addStaticData("F13",		&rvl::Keyboard::F13,		false)
					.addStaticData("F14",		&rvl::Keyboard::F14,		false)
					.addStaticData("F15",		&rvl::Keyboard::F15,		false)
				.endClass()
			.endNamespace();
	}

}
