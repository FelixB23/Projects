#ifndef __DEPLACEMENTIMPOSSIBLE__HPP__
#define __DEPLACEMENTIMPOSSIBLE__HPP__

    class DeplacementImpossible //classe d'exception
    {
        public:
            string m_message;
            DeplacementImpossible(string m="") {m_message=m;}
    };

#endif
