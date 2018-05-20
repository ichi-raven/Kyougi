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

	void move(const int R, const int C, std::vector<std::vector<Trout> > &stage);//移動

	void remove(const int R, const int C, std::vector<std::vector<Trout> > &stage);//撤去

	void deploy(const int R, const int C, const int COLOR, std::vector<std::vector<Trout> > &stage);//設置


private:

	int color;//色

	int mR;//現在地行

	int mC;//現在地列


};