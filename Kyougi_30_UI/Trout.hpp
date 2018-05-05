#pragma once






class Trout
{
public:
	Trout();

	int get_index_raw() const;

	int get_index_col() const;

	void set_point(int INDEX_R, int INDEX_C);

	void set_number(int number);

	int get_state() const;

	void set_state(int STATE);

private:
	int index_raw;//行側index

	int index_col;//列側index

	int number;//マスに書かれるであろう数値

	int state;//状態、constexprで指定する	


};