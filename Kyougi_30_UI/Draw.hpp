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
	
	void set_coodinate(const int R_NUM, const int C_NUM);//���W���̐ݒ�

	void Draw_line();//�g�`��

	void Draw_number(const int R, const int C, const int number);//���l�`��

	void Draw_color(const int R, const int C, const int COLOR);//�F�`��

	//void Draw_score(const int score);//�X�R�A���E��ɂł��`��

	void Draw_Agent(const int R, const int C, const int COLOR);//�G�[�W�F���g�`��

private:

	std::vector<std::vector<vec2> > Point;//�����ł����g��Ȃ��\���p���W,�e�}�X�̍�����W���i�[���Ă���


};
