#include <cstdio>
#include <deque>

using namespace std;

int main() {
    int T;
    int N, K;
    int element;

    scanf("%d", &T);

    while (T--) {
        deque<int> elements;

        scanf("%d %d", &N, &K);

        while (N--) {
            scanf("%d", &element);

            for (int i = 0; i < elements.size(); i++) {
                if (element > elements[i]) {
                    elements[i] = element;
                }
            }

            elements.push_back(element);

            if (elements.size() == K) {
                printf("%d ", elements.front());
                elements.pop_front();
            }
        }

        printf("\n");
    }

    return 0;
}
