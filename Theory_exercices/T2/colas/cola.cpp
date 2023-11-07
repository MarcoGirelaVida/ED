#include <cassert>
using namespace std;

class Queue{
    private:
        int * data;
        int size;
        int n;
        int first, last;

        void resize(int size);

        void copy(const Queue &Q){
            size = Q.size;
            n = Q.n;
            last = Q.last;
            first = Q.first;
            data = new int[size];

        }
    
    public:
        Queue(int size=10);
        Queue(const Queue & Q);
        ~Queue();
        
        Queue & operator=(const Queue & C);

        int size() const {return n;}

        bool empty() const {return n==0;}

        char front() const {
            assert(n!=0);
            return data[first];
        }

        void push(char c){
            if (n==size)
            {
                resize(2*size);
            }
            data[last] = c;
            last = (last + 1) % size;
            n++;
            
        }

        void pop(){
            assert(n!=0);

            first = (first+1)%size;
            n--;

            if (n <= size/4)
            {
                resize(size/2);
            }
            
        }
};
