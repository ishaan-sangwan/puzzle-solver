#ifndef MATRIX_H
#define MATRIX_H

#ifndef SAFE_STL
    #include<vector>
    using namespace std;

#endif

template <class Object>
class matrix
{
    public:
        matrix(int row, int colunmn) array( rows );
        {
            for ( int i =0 ; i < rows; i++ )
            {
                array[i].resize(column);
            }
        }

        matrix (const matrix & rhs) : array(rhs.array) { }

        const vector<Object> & operator[](int row) const
        {
            return array[row];
        }

        vector<Object> & operator[](int row)const
        {
            return array[row];
        }

        int numrows( ) const
        {
            return array.size();
        }

        int numcols( ) const
        {
            return numrows() > 0 ? array[0].size(): 0;
        }

        void push_back(const vector<Object> & newRow)
        {
            array.push_back(newRow);
        }

    private:
        vector<vector<Object>> array;

};


#endif