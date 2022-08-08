class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

		int n = gas.size();

		int i = 0, j = 0;
		int sum = 0;

        if(n==1){
            if(gas[0] - cost[0]<0){
                return -1;
            }
            return 0;
        }

		while (i != n) {
        
			int cur_cost=gas[j]-cost[j];
			if (i == (j + 1) % n ) {
				return i;
			}
			if (sum + cur_cost >= 0) {
				sum += cur_cost;
				j = (++j) % n;

			}
            cur_cost=gas[j]-cost[j];
			if (sum + cur_cost < 0) {
				if (i == j) {

					i++; j = (++j) % n;

				}
				else {
					sum -= (gas[i]-cost[i]);
					i++;

				}

			}
		}
		return -1;
	}
};