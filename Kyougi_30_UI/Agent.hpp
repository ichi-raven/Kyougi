#pragma once
#include<vector>


class Trout;


class Agent
{
public:
	//Agent();

	void set_point(const int R, const int C);

	void set_direction(const int MOVE_R, const int MOVE_C);

	int get_raw_point() const;

	int get_raw_dir() const;

	int get_col_point() const;

	int get_col_dir() const;

	void set_doing(const int DO);

	int get_doing() const;

	bool isSameTarget(const Agent& ANOTHER) const;

	bool isSamePoint(const Agent& ANOTHER) const;

	void set_color(const int STATE);

	int get_color() const;

	void move(std::vector<std::vector<Trout> > &stage);//�ړ�

	void remove(std::vector<std::vector<Trout> > &stage);//�P��

	void deploy(std::vector<std::vector<Trout> > &stage);//�ݒu


private:

	int color;//�F

	int mR;//���ݒn�s

	int mC;//���ݒn��

	int move_R;//�ړ���̍s�ւ̍�

	int move_C;// ����

	int Do;//���̃^�[���������邩


};