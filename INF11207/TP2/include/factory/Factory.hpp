
#ifndef FACTORY_HPP_
#define FACTORY_HPP_

typedef enum { FIRST } e_NAME;

namespace Factory
{

    class Factory {
    private:
        Factory () {}
        virtual ~Factory () {}

    public:
        /*
        ** ReturnType : Type of the class to return (no inheriting class)
        ** EnumType : Type of the enum used to get the type to return
        */
        template <typename ReturnType, typename EnumType>
        static ReturnType   *newObject(EnumType type, const std::string &param)
        {
            return (ReturnType::newInstance(type));
        };

        /* PROTOTYPE OF THE FUNCTION THAT HAS TO BE IMPLEMENTED EVERYTIME IN
        ** EACH INHERITING CLASSES
        ** These functions are called when the `newObject` method is called,
        ** depending on the enum type and the return type.
        */
        // static ReturnType     *newReturnType(EnumType type);

    };

}

#endif
