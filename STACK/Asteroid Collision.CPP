// 735. Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // collision will only occur if last element in stack is moving right and asteroid is moving left
        vector<int> st;
        for(int asteroid: asteroids)
        {
            bool destroyed = false;
            while(st.size() and st.back() > 0 and asteroid < 0){
                if(st.back() == -asteroid)
                {
                    st.pop_back();
                    destroyed = true;
                    break;
                } 
                else if(st.back() > -asteroid)
                {
                    destroyed = true;
                    break;
                }
                else
                    st.pop_back();
            }
            if(!destroyed)
                st.push_back(asteroid);
        }
        return st;
    }
};