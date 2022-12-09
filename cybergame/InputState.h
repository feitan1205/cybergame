#pragma once

enum class InputType {
	next,//Ÿ‚Ös‚­ƒ{ƒ^ƒ“
	shot
};

class InputState
{
private:
	int keypadState;
	int lastKeypadState;
	char keystate[256];
	char lastKeystate[256];
	int mouseState;
	int lastmouseState;
public:
	bool IsTriggered(InputType type)const;
	bool IsPressed(InputType type)const;
	void Update();
};

