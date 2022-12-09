#include "DxLib.h"
#include "game.h"
#include "Virus.h"

namespace {
	constexpr float kSpeed = 3.0;
}

//覐΃f�[�^�̏�����
Virus::Virus() {

	handle = 0;
	posX = 0;
	posY = 0;
	sizeX = 0;
	sizeY = 0;
	vecX = 0;
	vecY = 0;

}

Virus::~Virus()
{
}


//覐΂̍��W�f�[�^�̐ݒ�֐�
void Virus::SetPos() {

	posX = static_cast<float>(GetRand(500)) + 750;						//覐΂̏����ʒuX���W��750����1250�̊ԂŎ擾
	posY = (float)GetRand(Game::kScreenHeight - sizeY);						//覐΂̏����ʒuY���W����ʓ��Ŏ擾����		

}

//覐΂̃T�C�Y�ݒ�֐�
void Virus::SetSize() {

	GetGraphSize(handle, &sizeX, &sizeY);								//�摜�̃T�C�Y���擾����

}

//覐΂̃x�N�g���ݒ�֐�
void Virus::SetVec() {

	vecX = (float)(GetRand(1) + 1);										//X�����̃x�N�g����1��2�Ŏ擾����
	vecY = static_cast<float>(GetRand(100)) / 100 + (float)0.01;		//Y�����̃x�N�g����0.01����0.99�Ŏ擾����

	if (posY > 360) {													//覐΂̏����ʒu����ʉ������̎�

		vecY = -(vecY);													//Y�����̃x�N�g���𔽓]����

	}

}

//覐΂̉摜�f�[�^�ݒ�֐�
void Virus::SetImage() {

	handle = LoadGraph("data/virus.png");								//handle��覐΂̉摜�̃f�[�^���擾����

}

//覐΂̓���ݒ�֐�
void Virus::MoveMeteo() {

	posX -= vecX * kSpeed;														//X���W���x�N�g�����ړ�������
	posY += vecY * kSpeed;														//Y���W���x�N�g�����ړ�������

}

void Virus::Delete() {

	DeleteGraph(handle);												//覐΂̉摜�f�[�^��������������

}

//覐΂̕`��֐�
void Virus::Draw() {

	DrawGraphF(posX, posY, handle, true);								//覐΂�`�悷��

}