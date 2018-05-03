#include "DxLib.h"
#include<random>


int Key[256];

int gpUpdateKey()
{
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0)
		{ // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else
		{              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}			  // キーの入力状態を更新する



int get_Rand(int min, int max)//指定した値の範囲の整数乱数を出力する関数
{
	// 乱数生成器, パフォーマンス考えてstatic


	static std::random_device seed_generator;
	static std::default_random_engine random_engine(seed_generator());

	// random_engineの結果をmin ~ maxの範囲で返す
	auto a = std::uniform_int_distribution<>(min, max);

	return a(random_engine);

}

void myDraw_formatstring(int X, int Y, int cR, int cG, int cB, const char* str, int fonthandle)
{
	DrawFormatStringToHandle(X, Y, GetColor(255, 255, 255), fonthandle, str);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{






	ChangeWindowMode(true), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), SetGraphMode(800, 480, 16); //ウィンドウモード変更と初期化と裏画面設定と画面サイズ変更
	



									  // while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キー更新)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0 && Key[KEY_INPUT_ESCAPE] == 0)
	{




		

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;


}
