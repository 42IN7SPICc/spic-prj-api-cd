#ifndef SPIC_GAME_QUEUEUTIL_HPP
#define SPIC_GAME_QUEUEUTIL_HPP

#include <queue>
#include <stack>

namespace spic
{
    /**
     * @brief A util for std queue.
     */
    class QueueUtil
    {
        public:
            /**
             * @brief Reverse a queue.
             * @param queue The queue that needs reversing
             * @return A reversed queue.
             */
            template<class T>
            static void Reverse(std::queue<T>& queue)
            {
                std::stack<T> stack;

                while (!queue.empty())
                {
                    stack.push(queue.front());
                    queue.pop();
                }

                while (!stack.empty())
                {
                    queue.push(stack.top());
                    stack.pop();
                }
            }
    };
}


#endif //SPIC_GAME_QUEUEUTIL_HPP
