#include <iostream>
#include <cstring>

#define V 5

using namespace std;

void calc(int mdata[V][V], int fdata[V][V]){
    bool suitorEngaged[ V + 1 ];
    memset(suitorEngaged, false, sizeof(suitorEngaged));

    int brideOf[ V + 1 ];
    memset(brideOf, 0, sizeof(brideOf));

    int nSuitor = V;
    while(nSuitor){
        int freeSuitor;
        for(freeSuitor = 1; freeSuitor <= V; freeSuitor++)
            if(suitorEngaged[ freeSuitor ] == false)
                break;

        //Suitor Preferences
        //for(int i = 0; suitorEngaged[freeSuitor] == false && i < V; i++){
        for(int i = 0; i < V; i++){
            int preferredBride = mdata[i][freeSuitor];

            if(brideOf[preferredBride] == 0){
                brideOf[preferredBride] = freeSuitor;
                suitorEngaged[freeSuitor] = true;
                nSuitor--;
                break;
            }
            else{
                bool broken = false;
                for(int j = 0; j < V; j++){
                    if(fdata[j][preferredBride] == freeSuitor){
                        suitorEngaged[ brideOf[preferredBride] ]  = false;
                        brideOf[preferredBride] = freeSuitor;
                        suitorEngaged[freeSuitor] = true;
                        broken = true;
                        break;
                    }
                    else if(fdata[j][preferredBride] == brideOf[preferredBride]){
                        break;
                    }
                }
                if(broken)
                    break;
            }
        }
    }

    for(int i = 1; i <= V; i++){
        cout << i << "\t" << brideOf[i] << endl;
    }
}

int main(){
    int mdata[V][V] = {
            {2, 1, 2, 1, 5},
            {5, 2, 3, 3, 3},
            {1, 3, 5, 2, 2},
            {3, 4, 4, 4, 1},
            {4, 5, 1, 5, 4}
    };

    int fdata[V][V] = {
            {5, 4, 1, 3, 4},
            {1, 5, 4, 2, 2},
            {4, 2, 2, 4, 3},
            {2, 1, 3, 1, 5},
            {3, 3, 5, 5, 1}
    };

    calc(mdata, fdata);

    return 0;
}