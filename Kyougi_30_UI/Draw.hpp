#pragma once

class vec2
{
public:
	int x;

	int y;
};


class Draw
{
public:

	//Draw();

	void set_coodinate(const int X_NUM, const int Y_NUM);//���W���̐ݒ�

	void Draw_line();//�g�`��

	void Draw_number(const int X, const int Y, const int NUMBER);//���l�`��

	void Draw_color(const int X, const int Y, const int COLOR);//�F�`��

	//void Draw_score(const int SCORE);//�X�R�A���E��ɂł��`��

	void Draw_Agent(const int X, const int Y, const int COLOR);//�G�[�W�F���g�`��

private:

	std::vector<std::vector<vec2> > Point;//�����ł����g��Ȃ��\���p���W,�e�}�X�̍�����W���i�[���Ă���


};
