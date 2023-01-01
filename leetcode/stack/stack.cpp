class Solution {
public:
    int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for(auto& t : tokens) 
		if(t == "+" || t == "-" || t == "*" || t == "/") {
			int op1 = s.top(); s.pop();
			int op2 = s.top(); s.pop();
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;   
			s.push(op1);
		}
		else s.push(stoi(t));    // stoi - converts from string to int     
	return s.top(); 
}
};
/*
int evalRPN(vector<string>& tokens) {
	int top = 0;
	for(auto& t : tokens) 
		if(t == "+" || t == "-" || t == "*" || t == "/") {
			int op1 = stoi(tokens[--top]); 
			int op2 = stoi(tokens[--top]); 
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;   
			tokens[top++] = to_string(op1);
		}
		else tokens[top++] = t;
	return stoi(tokens[0]);
}
Time Complexity : O(N)
Space Complexity : O(1)
*/
