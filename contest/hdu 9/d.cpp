#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

struct Node{
    Node(int v = -1, int l = 0):value(v), level(l) { }
    int value;
    int level;
};

int main(int argc, char const *argv[])
{
    int n, m, a, b;
    int level[101];  // ��¼ÿ��ĸ���
    bool visited[101];  // �����ж��Ƿ��γɻ�
    while (cin >> n >> m && n != 0) {
        vector<int> node[101];
        Node parent[101];  // ��¼���ڵ�

        memset(level, 0, sizeof(level));
        memset(visited, false, sizeof(visited));
        bool isSucceed = true;

        for (int i = 0; i != m; ++i) {
            cin >> a >> b;
            if (a == b) {  // Ԫ��ָ������
                isSucceed = false;
                continue;
            }

            node[a - 1].push_back(b - 1);  // Ԫ��ֵ�Ǵ� 1 ��ʼ��
            if (parent[b - 1].value == -1)
                parent[b - 1].value = a - 1;
            else
                isSucceed = false;
        }

        bool hasRoot = false;  // �Ƿ��и��ڵ�
        if (isSucceed) {
            for (int i = 0; i != n; ++i) {
                if (!isSucceed)
                    break;
                if (parent[i].value == -1) {  // �Ӹ��ڵ����ÿһ����
                    hasRoot = true;
                    stack<int> s;
                    s.push(i);
                    while (!s.empty()) {
                        if (!isSucceed)
                            break;
                        int current = s.top();
                        visited[current] = true;
                        if (current != i)
                            parent[current].level = parent[parent[current].value].level + 1;  // �ӽڵ�level���ڸ��ڵ�+1

                        s.pop();
                        for (int j = 0; j != node[current].size(); ++j) {
                            if (visited[node[current][j]]) {  // �γ��˻�
                                isSucceed = false;
                                break;
                            }
                            s.push(node[current][j]);
                        }
                    }
                }
            }
        }
        if (isSucceed) {
            for (int i = 0; i != n; ++i) {
                level[parent[i].level]++;
            }
        }
        if (!isSucceed || !hasRoot) {
            cout << "INVALID" << endl;
            continue;
        }

        int levelMax = -1;
        int index = -1;
        for (int i = 0; i != n; ++i) {
            if (level[i] == 0)
                break;
            if (levelMax < level[i]) {
                levelMax = level[i];
            }
            index++;
        }
        cout << index << " " << levelMax << endl;
    }

    return 0;
}
