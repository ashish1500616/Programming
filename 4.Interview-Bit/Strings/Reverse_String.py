class Solution:
	# @param A : string
	# @return string
	def reverseWords(self, A):
		n_A=A.split(" ")
		ans=""
		for x in range(len(n_A)-1,0,-1,):
			ans=ans + " " + x
		return ans