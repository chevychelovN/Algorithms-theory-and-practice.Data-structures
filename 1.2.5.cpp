// Максимум в скользящем окне

#include <iostream>
#include <vector>

std::vector< int > B, C;

void build(const std::vector< int >& A, int k)
{
int n = A.size();
B.resize(n);
C.resize(n);
B.front() = A.front();
C.back() = A.back();
if (k != 1)k--;

for(int i1(1), i2(n - 2); i1 < n; i1++, i2--)
{
B[i1] = (i1 % k) ? std::max(A[i1], B[i1 - 1]) : A[i1];
C[i2] = ((i2 + 1) % k) ? std::max(A[i2], C[i2 + 1]) : A[i2];
}
}

int GetMax(int l, int k)
{
return std::max(C[l], B[l + k - 1]);
}

int main() {
std::size_t size;
std::cin >> size;

std::vector<int> A;
for(size_t i = 0; i < size; ++i)
{
int tmp;
std::cin >> tmp;
A.push_back(tmp);
}
int k;
std::cin >> k;

build(A, k);
for(size_t i = 0; i < size - k + 1; ++i)
{
std::cout << GetMax(i, k) << " ";
}
return 0;
}
