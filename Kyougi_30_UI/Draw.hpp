#pragma once

class Draw
{
public:

	Draw();

	void Draw_line(const int RAW_NUM, const int COL_NUM);//�g�`��

	void Draw_number(const int INDEX_X, const int INDEX_Y, const int NUMBER);//���l�`��

	void Draw_color(const int INDEX_X, const int INDEX_Y, const int COLOR);//�F�`��

	void Draw_score(const int SCORE);//�X�R�A���E��ɂł��`��

	void Draw_All();//�܂Ƃ�


};