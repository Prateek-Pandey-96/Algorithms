// 2080. Range Frequency Queries

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> indices;
    RangeFreqQuery(vector<int>& arr) {
        indices.clear();
        // indices are stored in ascednding order as well
        for(int i=0; i<arr.size(); i++)
            indices[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        vector<int>& positions = indices[value];
        int lidx = -1, ridx = -1;
        int low = 0, high = positions.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(positions[mid]==left){
                lidx = mid;
                break;
            }else if(positions[mid] > left){
                if(positions[mid]<=right)
                    lidx = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        low = 0, high = positions.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(positions[mid]==right){
                ridx = mid;
                break;
            }else if(positions[mid] > right){
                high = mid-1;
            }else{
                if(positions[mid]>=left)
                    ridx = mid;
                low = mid+1;
            }
        }
        if(ridx==lidx)
        {
            if(ridx!=-1)
                return 1;
            else
                return 0;
        }
        return ridx - lidx + 1;
    }
};