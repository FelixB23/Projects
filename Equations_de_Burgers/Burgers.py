#librairie necessaires
import numpy as np
import matplotlib.pyplot as plt
from scipy.sparse.linalg.dsolve import spsolve

#Donnees
v = 0.01 #viscosite
L = 2 #longueur du domaine
I = 100 #Nombre de points de discretisation en espace
h = L/I #pas de discretisation en espace
T = 10 #duree mesuree
K = 320 #Nombre de points de discretisation en temps
dt = T/K #pas de discretisation en temps
eps = 10**(-8) #seuil a obtenir pour la methode de Newton
m = 2 #m>1 parametre pour la condition initiale et la solution

def u0(x): #condition initiale
    return 2*v*np.pi*np.sin(np.pi*x)/(m+np.cos(np.pi*x))

def sol(x,t): #solution exacte a retrouver
    return 2*v*np.pi*np.exp(-np.pi**2*v*t)*np.sin(np.pi*x)/(m+np.exp(-np.pi**2*v*t)*np.cos(np.pi*x))

def F(Uold, V): #R^(I-1)² --> R^(I-1)
    #On ajoute aux vecteurs les limites aux bords du domaine (=0)
    Uold = np.concatenate([0, Uold, 0], axis = None) #vecteur de dimension I+1
    V = np.concatenate([0, V, 0], axis = None) #vecteur de dimension I+1
    
    return (1/dt + (V[2:I+1] - V[0:I-1])/(4*h) + v/(h**2))*V[1:I] - v/(2*h**2)*V[2:I+1] - v/(2*h**2)*V[0:I-1] \
            + (v/(h**2) + (Uold[2:I+1] - Uold[0:I-1])/(4*h) - 1/dt)*Uold[1:I] - v/(2*h**2)*Uold[2:I+1] - v/(2*h**2)*Uold[0:I-1]

def J(V): #R^(I-1) --> M_(I-1)(R)
    #On ajoute au vecteur les limites aux bords du domaine (=0)
    V = np.concatenate([0, V, 0], axis = None) #vecteur de dimension I+1
    
    #Construction de la Jacobienne J(uk) de dimension (I-1,I-1)
    J = np.diag(1/dt + (V[2:I+1] - V[0:I-1])/(4*h) + v/h**2) #diagonale
    J += np.diag((-v/(2*h**2) - V[2:I]/(4*h))*np.ones(I-2), -1) #sous-diagonale
    J += np.diag((-v/(2*h**2) + V[1:I-1]/(4*h))*np.ones(I-2), 1) #sur-diagonale
    return J;

#vecteur u0
Unew = u0(np.arange(h,L,h)) #vecteur de dimension I-1
Uold = np.copy(Unew) #representera le terme precedent

x = np.arange(0,L+h,h) #vecteur de dimension I+1

#Mise en place du graphique
plt.figure(figsize=(12,8)) #taille de la fenetre
plt.title('Equation de Burgers')
plt.xlabel('position')
plt.ylabel('valeur de u', rotation=90)
plt.plot(x, u0(x), 'm', linewidth=3, label='fonction au temps initial')

#'''
#Mise en place du graphique interactif
lineSol, = plt.plot(x,u0(x), 'r', linewidth=3, label='solution')
lineApp, = plt.plot(x,np.concatenate([0, Unew, 0], axis = None), 'k--', linewidth=2, label='approximation')
#'''

plt.legend() #affichage de la legende

C = ['b','c--','y','g--','c','b--','g','y--'] #Couleurs des courbes
c = 0

print('U[0] = ',np.concatenate([0, Unew, 0], axis = None)) #affichage dans la console de de u au temps 0
print("\n")

for k in range(1,K+1): #boucle dans laquelle on va calculer les vecteurs uk 
    n = 0 #compte le nombre d'itération pour que la méthode de Newton converge
    dV = np.ones(I-1) #pour rentrer dans la boucle du while
    V = np.copy(Uold) #On choisit comme point de depart pour la méthode de Newton le terme precedent (dans le temps)

    while max(abs(dV))>eps: #boucle dans laquelle on va effectuer les iterations de Newton
        dV = spsolve(J(V),-F(Uold,V)) #resolution de J*du = -F (multiplié par dt)
        V += dV
        n += 1
        
    Unew = V #le terme suivant correspond au resultat obtenu par la methode de Newton
    Uold = Unew #On garde en memoire U au temps precedent
    
    #Affichage de 8 itération de temps dans la console (reparties uniformement)
    if k%int(K/8)==0: 
        print('temps t = %1.2f' %(k*dt))
        print('approximation : ', np.concatenate([0, Unew, 0], axis = None))
        print('solution : ', sol(x,k*dt))
        #norme de la différence entre l'approximation et la solution
        print('ecart : ', np.linalg.norm(np.concatenate([0, Unew, 0], axis = None) - sol(x,k*dt))) 
        print('nb itération n = ', n)
        print('\n')
    
    #Mise a jour du graphique : 4 affichages persistants repartis uniformement dans le temps
    if k%int(K/4)==0: 
        #affichage de la solution exacte (trait continu)
        plt.plot(x,sol(x,k*dt), C[c], linewidth=3, label='solution au temps t = %1.2f' %(k*dt)) 
        #affichage de l'approximation en pointillé
        plt.plot(x, np.concatenate([0, Unew, 0], axis = None),  C[c+1], linewidth=2, label='approximation au temps t = %1.2f' %(k*dt)) 
        plt.legend() #affichage de la legende
        c += 2
        
    #'''
    #graphique interactif
    lineSol.set_xdata(x)
    lineSol.set_ydata(sol(x,k*dt))
    lineApp.set_xdata(x)
    lineApp.set_ydata(np.concatenate([0, Unew, 0], axis = None))
    plt.pause(1/K) #plus K est grand, moins la pause entre deux iterations sera longue
    #'''
