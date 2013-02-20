#ifndef _GUARD_UI_ListViewItemComparer
#define _GUARD_UI_ListViewItemComparer
//[for MainForm's ListView components]Implements the manual sorting of items by columns. 

namespace CICMS_UI {
	ref class ListViewItemComparer: public System::Collections::IComparer
	{
	public: ListViewItemComparer(int column, bool sortOrder);

	private: int _col;
	private: bool _sort;

	public: virtual int Compare(Object^ x, Object^ y);
	private: int Compare_s(System::String^ s1, System::String^ s2);
	private: bool is_number(System::String^ s);//this function should be in the handler/logic part

	};
}
#endif