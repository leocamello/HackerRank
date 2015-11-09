#include <algorithm>
#include <cstdio>
#include <deque>

using namespace std;

int main() {
    int T, N, K;
    int element;

    scanf("%d", &T);

    while (T--) {
        int maximum = 0;
        deque<int> elements;

        scanf("%d %d", &N, &K);

        while (N--) {
            scanf("%d", &element);

            maximum = max(element, maximum);

            elements.push_back(element);

            if (elements.size() == K) {
                printf("%d ", maximum);

                if (elements.front() == maximum) {
                    maximum = 0;
                    for (int i = 1; i < K; i++) {
                        maximum = max(elements[i], maximum);
                    }
                }

                elements.pop_front();
            }
        }

        printf("\n");
    }

    return 0;
}
