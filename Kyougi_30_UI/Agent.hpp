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

	void set_color(const int STATE);

	int get_color() const;

	void move(const int R, const int C, std::vector<std::vector<Trout> > &stage);//�����w�肵�Ĉړ��A������constexpr

	void remove(const int R, const int C, std::vector<std::vector<Trout> > &stage);//�����w�肵�ēP���A������ry

	void deploy(const int R, const int C, const int COLOR, std::vector<std::vector<Trout> > &stage);//�����w�肵�Đݒu�A�����A�F��ry


private:

	int color;//�F

	int mR;//���ݒn�s

	int mC;//���ݒn��


};