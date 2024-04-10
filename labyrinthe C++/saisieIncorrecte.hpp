#ifndef __SAISIEINCORRECTE__HPP__
#define __SAISIEINCORRECTE__HPP__

    class SaisieIncorrecte //classe d'excpeption
    {
        public:
            string m_message;
            SaisieIncorrecte(string m="") {m_message=m;}
    };

#endif
