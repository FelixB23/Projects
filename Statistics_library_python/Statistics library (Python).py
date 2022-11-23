import random

def listealeatoire(longueur,intervalle):
    L=[]
    for i in range(0,longueur):
        L.append(random.randint(intervalle[0],intervalle[1]))
    return L
#print(listealeatoire(5,[0,10]))

def listealeatoiredepouille(longueur,intervalle,effectifmax):
    L=[]
    for i in range(0,longueur):
        a=random.randint(intervalle[0],intervalle[1])
        while a in [i[0] for i in L]:
            a=random.randint(intervalle[0],intervalle[1])
        L.append((a,random.randint(1,effectifmax)))
    return L
#l=listealeatoiredepouille(10,[0,20],10)

def effectif(l): #transforme la liste brute en une version dépouillée
    liste=l[:]
    l1=[]
    c=0
    for j in liste: #scan de la série brute
        for i in liste: #on compte le nombre d'aparitions que la valeur 
            if i == j:
                c+=1
        if (j,c) not in l1:   # ajoute le tuple (valeur, effetif de celle-ci) à la série dépouillée 
            l1.append((j,c))  # en vérifiant que la valeur ajouté n'est pas déjà présente dans la liste
        c=0                                                
    return l1

def mode(l): #prend en entrée une liste (série brute) et retourne une liste contenant la/les valeurs apparaissant le plus de fois
    l1=effectif(l)
    maxi=l1[0]
    bon=[]
    for y in l1:
        if maxi[1]<y[1]:
            maxi=y
            bon.clear()
            bon.append(y[0])
        elif maxi[1]==y[1]:
            bon.append(y[0])        
    return bon
#print(mode(l))

def mode2(l): #prend en entrée une liste (série brute) et retourne une liste contenant la/les valeurs apparaissant le plus de fois
    maxi=0
    m=[]
    for i in l:
        n=0
        for j in l:
            if i==j:
                n+=1
        if n>maxi and i not in m:
            maxi=n
            m.clear()
            m.append(i)
        if n==maxi and i not in m:
            m.append(i)
    return m
#print(mode2(l))

def moyenne(l): #prend en entrée une liste (série brute) et retourne un nombre (la moyenne de la série)
    return sum(l)/len(l)
#print(moyenne(l))

def medianne(l): #prend en entrée une liste (série brute) et retourne un nombre (la médianne de la série)
    if len(l) % 2 != 0:
        return sorted(l)[len(l)//2]
    else:
        return moyenne([sorted(l)[(len(l)//2)-1],sorted(l)[(len(l)//2)]])
#print(medianne(l))

def quantiles(l,q): #prend en entrée une liste (série brute) ainsi que le coefficient (q) qui sert a découper la série et retourne une liste des nombres qui découpent la série en q parties (ex q=4 pour quartile)
    lq=[] #liste qui retournera les quantiles
    for i in range(1,q):
        k=i*(len(l)+1)/(q) #découpage de la liste en q parties
        if int(k)==k: #si k est entier, on prend la k-ième valeur de la liste classée par ordre croissant (d'indice k-1)
            lq.append(sorted(l)[int(k)-1])
        else: #si k n'est pas entier, on prend la moyenne de la partie entière de k et du terme suivant.
            lq.append(moyenne([sorted(l)[int(k)-1],sorted(l)[int(k)]]))
    return lq
#print(quantiles(l,4))

def etendue(l): #prend en entrée une liste (série brute) et retourne un nombre (l'étandue de la série)
    return max(l)-min(l)
#print(etendue(l))

def ecartMoyen(l): #prend en entrée une liste (série brute) et retourne un nombre (l'écart moyen de la série)
    return sum([((moyenne(l)-i)**2)**(1/2) for i in l])/len(l)
#print(ecartMoyen(l))

def variance(l): #prend en entrée une liste (série brute) et retourne un nombre (la variance de la série)
    return sum([(i-moyenne(l))**2 for i in l])/len(l) 
#print(variance(l))

def ecartType(l): #prend en entrée une liste (série brute) et retourne un nombre (l'écart type de la série)
    return variance(l)**(1/2)    
#print(ecartType(l))

def moments(l,k): #prend en entrée une liste (série brute) ainsi que k un nombre qui est l'ordre du moment calculé et retourne un nombre (le moment de la série)
    return sum([i**k for i in l])/len(l)
#print(moments(l,2))

def momentsCentre(l,k): #prend en entrée une liste (série brute) ainsi que k un nombre qui est l'ordre du moment calculé et retourne un nombre (la moment centré de la série)
    return sum([(i-moyenne(l))**k for i in l])/len(l)    
#print(momentsCentre(l,2))

def coefFicher1(l): #prend en entrée une liste (série brute) et retourne un nombre (le premier coefficient de Ficher de la série)
    return momentsCentre(l,3)/(momentsCentre(l,2)**(3/2))
#print(coefFicher1(l))

def coefFicher2(l): #prend en entrée une liste (série brute) et retourne un nombre (le second coefficient de Ficher de la série)
    return momentsCentre(l,4)/(momentsCentre(l,2)**2)    
#print(coefFicher2(l))

def covariance(l1,l2):  #prend en entrée deux listes (séries brutes) et retourne un nombre (la covariance de ces deux séries)
    return sum([(i-moyenne(l1))for i in l1][k]*[(j-moyenne(l2)) for j in l2][k] for k in range(len(l1)))/len(l1)
#print(covariance(l1,l2))

def coefCorelation(l1,l2): #prend en entrée deux listes (séries brutes) et retourne un nombre (le coefficient de corélation de ces deux séries)
    return covariance(l1,l2,moyenne(l1),moyenne(l2))/(ecartType(l1)*ecartType(l2))
#print(coefCorelation(l1,l2))

def passpass(l):  #transforme une liste dépouillée en liste brute
    ld=[]
    for i in l:
        for _ in range(i[1]):
            ld.append(i[0])
    return ld
#print(passpass(ld))
    
class Stats_d(object):
    
    def __init__(self,l):
        c=0
        if type(l)==type([]) and l!=[]: #l doit être une liste non vide
            a=True
            for x in l: #l doit contenir des tuples de 2 éléments : un réel et un entier positif non nul
                if type(x)!=type(()) or len(x)!=2 or (type(x[0])!=int and type(x[0])!=float) or type(x[1])!=int or x[1]<=0:
                    a=False
            if a==True:
                for x in l:
                    for i in l:
                        if x[0]==i[0]:
                            c+=1
        if c==len(l): #Vrai si toutes les conditions au-dessus sont réunies et que le 1er élément de chaque tuple est unique
            self.l=l
        else:
            self.l=[]
    
    def tri_d(self): # tri une liste dépouillée
        l1,l2=[i[0] for i in self.l],[]
        l1.sort()
        for i in l1:
            for j in self.l:
                if j[0]==i:
                    l2.append(j)
        return l2

    def mode_d(self): 
        ind=0
        bon=[]
        for i in self.l:
            if i[1] > ind:
                ind = i[1]
                bon.clear()
                bon.append(i[0])
                if i[1] == ind:
                    bon.append(i[0])
                    return bon

    def moy_d(self):
        return sum([i[0]*i[1] for i in self.l])/sum([i[1] for i in self.l])

    def variance_d(self):
        return sum([(i-self.moy_d())**2 for i in self.l])/len(self.l)
    
    def ecartype_d(self):
        return self.variance_d()**(1/2)
    
    def coefFicher1_d(self):  #prend en entrée une liste dépouillée et retourne un nombre (le premier coefficient de Ficher de la série)
        return self.momentsCentre_d(3)/(self.momentsCentre_d(2)**(3/2))

    def coefFicher2_d(self): #prend en entrée une liste dépouillée et retourne un nombre (le deuxième coefficient de Ficher de la série)
        return self.momentsCentre_d(4)/(self.momentsCentre_d(2)**2) 

    def moments_d(self,k):
        if type(k)==int and k>0:
            return sum(i[1]*i[0]**k for i in self.l)/sum(i[1] for i in self.l)
        else:
            print('veuillez entrer un nombre entier positif non nul en paramètre de cette fonction')
            return 0

    def momentsCentre_d(self,k): #prend en entrée une liste dépouillée ainsi que k un nombre qui est l'ordre du moment calculé et retourne un nombre (la moment centré de la série)
        if type(k)==int and k>0:
            return sum([((i[0]-self.moy_d())**k)*i[1] for i in self.l])/sum([i[1] for i in self.l])
        else:
            print('veuillez entrer un nombre entier positif non nul en paramètre de cette fonction')
            return 0

    def quantile_d(self,q):
        if type(q)==int and q>0:
            lq=[]
            long=sum(a[1] for a in self.l) #nombre de valeurs dans la liste : somme des effectifs
            for i in range(1,q):
                k=i*(long+1)/q
                compteur,x=0,-1 #on cherche quel nombre se situe à la k-ième place dans la liste de tuple triée par ordre croissant.
                while compteur<=k-1:
                    x+=1
                    compteur+=self.tri_d()[x][1]
                if int(k)==k or compteur>k: #si k est entier ou compris entre deux même valeur, on prend la valeur du x-ième tuple de la liste triée.
                    lq.append(self.tri_d()[x][0])
                else: #si k-1<compteur<k, on prend la moyenne des valeurs du x-ième tuple et du (x+1)ième tuple.
                    lq.append((self.tri_d()[x][0]+self.tri_d()[x+1][0])/2)
            return lq
        else:
            print('veuillez entrer un nombre entier positif non nul en paramètre de cette fonction')
            return 0

L=listealeatoiredepouille(5,[0,50],2)
print(L)
d=Stats_d(L)
print(d.quantile_d(4))



'''import statistics
L=listealeatoire(20,[0,50])
print('liste:',L)
print('moyenne à la main:',moyenne(L),', moyenne avec le module statistic:',statistics.mean(L))
print('variance à la main:',variance(L),', variance avec le module statistic:',statistics.pvariance(L))
print('écartype à la main:',ecartType(L),', écartype avec le module statistic:',statistics.pstdev(L))
print('médiane à la main:',medianne(L),', médiane avec le module statistic:',statistics.median(L))
print('mode à la main:',mode(L))#', mode avec le module statistic:',statistics.mode(L)) ne marche que lorsqu'il est unique
print('quartile à la main:',quantiles(L,4),', quartile avec le module statistic:') #statistics.quantile(L,4)) ne marche pas'''