import svgwrite
#on importe la bibliotheque svgwrite, qui permet de dessiner de nombreuses figures au format SVG
svgwrite.Drawing(debug=True)#affiche les erreurs(exceptions)
d = svgwrite.Drawing('vasarely.svg',profile='full')

from math import cos, acos, sin, pi, atan, sqrt, degrees

def méthode_1(a,OS):
    return a*(1-sin(atan(a/OS))*(cos(pi/2-atan(a/OS))-sqrt((cos(pi/2-atan(a/OS)))**2-(1-(R/a)**2))))


def d_path(r,R,Xc,Yc,OS,moitié):
    OC=sqrt((Xc-r*n)**2 + (Yc-r*n)**2) #OC est la distance entre O et le centre du petit cercle non déformé.
    OC_proj=méthode_1(OC,OS) #OC_proj est la distance entre O et le centre du petit cercle déformé.
    OD=OC-r
    OD_proj=méthode_1(OD,OS)
    DC_proj=OC_proj - OD_proj #rayon en x du 1er demi-cercle déformé (ou en y pour les cercle de l'axe y)
    OE=OC+r
    OE_proj=méthode_1(OE,OS) 
    EC_proj=OE_proj-OC_proj #rayon en x du 2ème demi-cercle déformé (ou en y pour les cercle de l'axe y)
    if Xc==r*n or Yc==r*n: #Tous les centre situés sur l'axe des abscisses ou des ordonnées
        OA=OB=sqrt(r**2 + OC**2) #théorème de pythagore
        OA_proj=OB_proj=méthode_1(OA,OS)
        AC_proj=sqrt(OA_proj**2 - OC_proj**2) #rayon en y du cercle déformé (ou en x pour les cercle de l'axe y)
        if Xc==r*n: #Cercles de l'axe des ordonnées
            Xa = Xc + AC_proj
            Xb = Xc - AC_proj
            if Yc<r*n: #Cercles de l'axe des ordonnées situés sur la moitié supérieure du grand cercle
                Ya = Yb = r*n - OC_proj
                if moitié==1:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,AC_proj,DC_proj,0,0,1,Xb,Yb)
                if moitié==2:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,AC_proj,EC_proj,0,1,0,Xb,Yb)
            if Yc>r*n:# Cercles de l'axe des ordonnées situés sur la moitié inférieure du grand cercle
                Ya = Yb = r*n + OC_proj
                if moitié==1:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,AC_proj,DC_proj,0,1,0,Xb,Yb)
                if moitié==2:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,AC_proj,EC_proj,0,0,1,Xb,Yb)
        if Yc==r*n: #Cercles de l'axe des abscisses
            Ya = Yc + AC_proj
            Yb = Yc - AC_proj
            if Xc<r*n: #Cercles de l'axe des abscisses situés sur la moitié inférieure du grand cercle
                Xa = Xb = r*n - OC_proj
                if moitié==1:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,DC_proj,AC_proj,0,1,0,Xb,Yb)
                if moitié==2:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,EC_proj,AC_proj,0,0,1,Xb,Yb)
            if Xc>r*n: #Cercles de l'axe des abscisses situés sur la moitié supérieure du grand cercle
                Xa = Xb = r*n + OC_proj
                if moitié==1:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,DC_proj,AC_proj,0,0,1,Xb,Yb)
                if moitié==2:
                    return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,EC_proj,AC_proj,0,1,0,Xb,Yb)
    alpha=atan(abs((r*n-Yc)/(Xc-r*n)))
    if (Xc<n*r and Yc>n*r) or (Xc>n*r and Yc<n*r): #Cercles des quarts en bas à gauche et en haut à droite
        OA=sqrt((Xc + r*cos(alpha + pi/2) - r*n)**2 + (r*n - Yc + r*sin(alpha + pi/2))**2)
        OA_proj=méthode_1(OA,OS)
        OB=sqrt((Xc + r*cos(alpha - pi/2) - r*n)**2 + (r*n - Yc + r*sin(alpha - pi/2))**2)
        OB_proj=méthode_1(OB,OS)
        AC_proj=sqrt(OA_proj**2 - OC_proj**2)
        if Xc>n*r and Yc<n*r: #Cercles du quart en haut à droite
            Xa=r*n + OA_proj*cos(alpha + acos(OC_proj/OA_proj)) #acos(OC_proj/OA_proj) est l'angle OC'A' 
            Ya=r*n - OA_proj*sin(alpha + acos(OC_proj/OA_proj)) #mais aussi l'angle OB'C'
            Xb=r*n + OB_proj*cos(alpha - acos(OC_proj/OA_proj))
            Yb=r*n - OB_proj*sin(alpha - acos(OC_proj/OA_proj))
        if Xc<n*r and Yc>n*r: #Cercles du quart en bas à gauche
            Xa=r*n + OA_proj*cos(alpha + pi + acos(OC_proj/OA_proj))
            Ya=r*n - OA_proj*sin(alpha + pi + acos(OC_proj/OA_proj))
            Xb=r*n + OB_proj*cos(alpha + pi - acos(OC_proj/OA_proj))
            Yb=r*n - OB_proj*sin(alpha + pi - acos(OC_proj/OA_proj))
        if moitié==1:
            return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,DC_proj,AC_proj,-degrees(alpha),1,0,Xb,Yb)
        if moitié==2:
            return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,EC_proj,AC_proj,-degrees(alpha),0,1,Xb,Yb)
    if (Xc>n*r and Yc>n*r) or (Xc<n*r and Yc<n*r): #Cercles des quarts en bas à droite et en haut à gauche
        OA=sqrt((Xc + r*cos(pi/2 - alpha) - r*n)**2 + (Yc - r*sin(pi/2 - alpha) - r*n)**2)
        OA_proj=méthode_1(OA,OS)
        OB=sqrt((Xc + r*cos(-pi/2 - alpha) - r*n)**2 + (Yc - r*sin(-pi/2 - alpha) - r*n)**2)
        OB_proj=méthode_1(OB,OS)
        AC_proj=sqrt(OA_proj**2 - OC_proj**2)
        if Xc>n*r and Yc>n*r: #Cercles du quart en bas à droite
            Xa=r*n + OA_proj*cos(-alpha + acos(OC_proj/OA_proj))
            Ya=r*n - OA_proj*sin(-alpha + acos(OC_proj/OA_proj))
            Xb=r*n + OB_proj*cos(-alpha - acos(OC_proj/OA_proj))
            Yb=r*n - OB_proj*sin(-alpha - acos(OC_proj/OA_proj))
        if Xc<n*r and Yc<n*r: #Cercles du quart en haut à gauche
            Xa=r*n + OA_proj*cos(pi - alpha + acos(OC_proj/OA_proj))
            Ya=r*n - OA_proj*sin(pi - alpha + acos(OC_proj/OA_proj))
            Xb=r*n + OB_proj*cos(pi - alpha - acos(OC_proj/OA_proj))
            Yb=r*n - OB_proj*sin(pi - alpha - acos(OC_proj/OA_proj))
        if moitié==1:
            return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,DC_proj,AC_proj,degrees(alpha),1,0,Xb,Yb)
        if moitié==2:
            return 'M{} {} A{} {} {} {} {} {} {}'.format(Xa,Ya,EC_proj,AC_proj,degrees(alpha),0,1,Xb,Yb)
            #fin de la fonction
    

n=int(input('Saisissez le nombre de cercles sur la largeur et sur la longueur (valeur par défaut : 21) : '))
r=int(input('Saisissez le rayon de chaque cercle (valeur par défaut : 20) : '))
R=int(input('Saisissez le rayon de la zone de déformation ou de la loupe (valeur par défaut : 340) : '))
OS=int(input('Saisissez le facteur de déformation du cercle (par défaut, la valeur de ce facteur est égale \
             au rayon de la zone de déformation. Diminuez la valeur pour un grossissement plus important) : '))


#grand cercle rouge qui fait l'effet loupe:
d.add(d.circle(center=(n*r,n*r),r=R,stroke=svgwrite.rgb(255, 0, 0 ,'%'),fill='white'))
#les parametres de la fonction circle:
#coordonnees du centre : on le positionne au centre de la figure de n*n cercles
#rayon : R
#stroke : couleur contour
#fill : couleur remplissage


#Yc est l'ordonnée du centre d'un petit cercle et Xc en est l'abscisse. 
#On commence avec Xc=Yc=r, puis on trace les cercles ligne par ligne avec un pas de 2r jusqu'à 
#n lignes et n colonnes de cercles.
for Xc in range( r, 2*r*n, 2*r): 
    for Yc in range(r, 2*r*n, 2*r):
#On commence par representer tous les cercles normaux situés à l'extérieur du grand cercle rouge.
        if (Xc-n*r)**2 + (Yc-n*r)**2 >= (R+r)**2:
            d.add(d.circle(center=(Xc,Yc),r=r,stroke=svgwrite.rgb(0, 255, 0 ,'%'),fill='white'))
        #On représente maintenant les cercles déformés à l'intérieur du grand cercle rouge.
        if (Xc-n*r)**2 + (Yc-n*r)**2 <= (R-r)**2:
            if Xc==Yc==r*n:#cercle du centre (s'il y en a un)
                d.add(d.circle(center=(Xc,Yc),r=méthode_1(r,OS),stroke=svgwrite.rgb(0, 255, 0 ,'%'),fill='white'))
            else:#Pour les cercles déformés, on utilise 2 path avec la fonction d_path ci-dessus.
                d.add(d.path(d=d_path(r,R,Xc,Yc,OS,1),stroke=svgwrite.rgb(0, 255, 0 ,'%'),fill='white'))
                d.add(d.path(d=d_path(r,R,Xc,Yc,OS,2),stroke=svgwrite.rgb(0, 255, 0 ,'%'),fill='white'))
                
d.save()