#include "../common/common.h"

class Segment_tree_zkw {
    private:
        int tn;
    public:
        std::vector<int> t;
        std::vector<int> num;

        void init(int N) {
            // printf("N:%d\n",N);
            t.resize((N + 1)<<2);
            num.resize((N + 1)<<2);
            // printf("t.size:%d\n",t.size());
            // printf("num.size:%d\n",num.size());
            int len = (N+1)<<2;
            // printf("len:%d\n",len);
            for(int i = 0; i <= len; i++){
                t[i] = INFINITY;
                // num[i] = 0;
            }
            tn = 1;
            while(tn < N) tn <<= 1;
            --tn;
            for (int i = 1; i <= N; ++i) 
                num[i + tn] = i;
        }

        void change(int p, const int &k) {
            p += tn; t[p] = k; p >>= 1;
            while (p) {
                if (t[p<<1] < t[p<<1|1]) {
                    t[p] = t[p<<1];
                    num[p] = num[p<<1];
                }
                else {
                    t[p] = t[p<<1|1];
                    num[p] = num[p<<1|1];
                }
                p >>= 1;
            }
        }
};