#include<vector>

namespace Tris
{
    class tris
    {
        private:
            std::vector<char> cell;
            char player = 'X';

        public:
            tris();
            void changePlayer();
            void Move();
    
    }
}
