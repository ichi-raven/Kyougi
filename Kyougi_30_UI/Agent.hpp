#pragma once
#include<vector>


class Trout;


class Agent
{
public:
	//Agent();

	void set_point(const int R, const int C);

	int get_raw_point() const;

	int get_col_point() const;

	bool isSamePoint(const Agent& ANOTHER, const int MOVE_R, const int MOVE_C) const;

	void set_color(const int STATE);

	int get_color() const;

	void move(const int R, const int C, std::vector<std::vector<Trout> > &stage);//�ړ�

	void remove(const int R, const int C, std::vector<std::vector<Trout> > &stage);//�P��

	void deploy(const int R, const int C, const int COLOR, std::vector<std::vector<Trout> > &stage);//�ݒu


private:

	int color;//�F

	int mR;//���ݒn�s

	int mC;//���ݒn��


};