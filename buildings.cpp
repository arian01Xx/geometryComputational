#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
//GEOMETRIA COMPUTACIONAL
class SolutionTwentyFour{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        //alturas
        multiset<int> height;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> ans;

        set<int> st; //para almacenar x unicas, puntos criticos de los edificios
        int j=0;

        //agrega x, y a st
        for(int i=0; i<buildings.size(); i++){
            st.insert(buildings[i][0]);
            st.insert(buildings[i][1]);
        }

        for(auto i: st){
            while(!pq.empty() && pq.top().first <= i){
            	//eliminar altura del edificio que ya no afecta
                height.erase(height.find(pq.top().second));
                pq.pop();
            }
            //insertar nuevos edificios que comienzan en i
            while(j<buildings.size() && buildings[j][0]==i){
            	//y, altura
                pq.push({buildings[j][1],buildings[j][2]});
                height.insert(buildings[j][2]);
                j++;
            }

            if(height.size()==0 && (ans.size()==0 || ans[ans.size()-1][1] != 0)){
            	//ultimo vector segundo elemento diferente a 0
            	//entonces se agrega el 0 para que finalice abajo totalmente
                ans.push_back({i,0});
            }else if(height.size()>0){
                auto it=height.rbegin();
                if(ans.size()==0 || ans[ans.size()-1][1] != *it){
                	//agregar el cambio en altura mas alta
                    ans.push_back({i,*it});
                }
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}