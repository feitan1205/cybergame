#pragma once
class Aim
{
public:

	Aim();								//�G�C��������������֐�
	~Aim();
	void SetPos();						//�G�C���̍��W��ݒ肷��֐�
	int GetPosX() { return posX; }		//�G�C���̍��WX���擾����֐�
	int GetPosY() { return posY; }		//�G�C���̍��WY���擾����֐�
	void Draw();						//�G�C����`�悷��֐�

private:

	int posX;							//X���W�̕ϐ�
	int posY;							//Y���W�̕ϐ�

};

