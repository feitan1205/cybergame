#pragma once

enum class InputType {
	next,//���֍s���{�^��
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

