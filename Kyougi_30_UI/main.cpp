#include "DxLib.h"
#include<random>


int Key[256];

int gpUpdateKey()
{
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0)
		{ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		}
		else
		{              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}			  // �L�[�̓��͏�Ԃ��X�V����



int get_Rand(int min, int max)//�w�肵���l�͈̔͂̐����������o�͂���֐�
{
	// ����������, �p�t�H�[�}���X�l����static


	static std::random_device seed_generator;
	static std::default_random_engine random_engine(seed_generator());

	// random_engine�̌��ʂ�min ~ max�͈̔͂ŕԂ�
	auto a = std::uniform_int_distribution<>(min, max);

	return a(random_engine);

}

void myDraw_formatstring(int X, int Y, int cR, int cG, int cB, const char* str, int fonthandle)
{
	DrawFormatStringToHandle(X, Y, GetColor(255, 255, 255), fonthandle, str);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{






	ChangeWindowMode(true), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), SetGraphMode(800, 480, 16); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�Ɖ�ʃT�C�Y�ύX
	



									  // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�X�V)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
	{




		

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;


}
