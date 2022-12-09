#pragma once
class SceneManager;
class InputState;
class Scene
{
protected:
	SceneManager& manager_;
public:
	Scene(SceneManager& manager):manager_(manager) {}
	virtual ~Scene() {};

	virtual void Init() = 0;
	//�V�[�����X�V����
	virtual void Update(const InputState& input) = 0;
	//�V�[����`�悷��
	virtual void Draw() = 0;
};

