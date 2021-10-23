#ifndef BEHAVIOURSCRIPT_H_
#define BEHAVIOURSCRIPT_H_

#include "Component.hpp"
#include "Collider.hpp"

namespace spic {

    class BehaviourScript : public Component {
        public:
            /**
             * @brief TODO
             */
            virtual void OnStart();

            /**
             * @brief TODO
             */
            virtual void OnUpdate();

            /**
             * @brief Sent when another object enters a trigger collider
             *        attached to this object (2D physics only).
             */
            virtual void OnTriggerEnter2D(const Collider& collider);

            /**
             * @brief Sent when another object leaves a trigger collider
             *        attached to this object (2D physics only).
             */
            virtual void OnTriggerExit2D(const Collider& collider);

            /**
             * @brief Sent each frame where another object is within a trigger
             *        collider attached to this object (2D physics only).
             */
            virtual void OnTriggerStay2D(const Collider& collider);

            /**
             * @brief Whether the script has been started.
             * @param started desired value
             */
            void Started(bool started) { _started = started; }

            /**
             * @brief Whether the script has been started.
             * @return current value
             */
            bool Started() const { return _started; }

        private:
            bool _started = false;
    };

}

#endif // BEHAVIOURSCRIPT_H_
