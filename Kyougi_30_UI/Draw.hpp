#pragma once

class Draw
{
public:

	Draw();

	void set_coodinate(const int RAW_NUM, const int COL_NUM);//���W���̐ݒ�

	void Draw_line();//�g�`��

	void Draw_number(const int INDEX_X, const int INDEX_Y, const int NUMBER);//���l�`��

	void Draw_color(const int INDEX_X, const int INDEX_Y, const int COLOR);//�F�`��

	void Draw_score(const int SCORE);//�X�R�A���E��ɂł��`��

	void Draw_Agent(const int INDEX_X, const int INDEX_Y, const int COLOR);//�G�[�W�F���g�`��

private:

	std::vector<std::vector<int[2]> > Point;//�����ł����g��Ȃ��\���p���W


};