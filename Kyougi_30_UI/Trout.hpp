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
	int index_raw;//�s��index

	int index_col;//��index

	int number;//�}�X�ɏ������ł��낤���l

	int state;//��ԁAconstexpr�Ŏw�肷��	


};