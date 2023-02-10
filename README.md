# 42_Containers
Prompt : recode c++ containers from scratch


## About the project

<wip>

### Definition of a container

> Containers are objects that store other objects. They control allocation and deallocation of these objects through constructors, destructors, insert and erase operations.
Source : [Norme ISO IEC 14882/1998](https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf)

They are two categories of containers :
1. **Sequences** (deque, list, queue, stack, vector)

	A sequence is a kind of container that organizes a finite set of objects, all of the same type, into a strictly linear arrangement.

	`vector` should be used by default.
	`list` should be used when there are frequent insertions and deletions from the middle of the sequence.
	`deque` should be used when most insertions and deletions take place at the beginning or at the end of the sequence.

	![img](https://hackingcpp.com/cpp/std/sequence_containers_thumb.png)
	[Source](https://hackingcpp.com/cpp/std/sequence_containers.html)

2. **Associatives containers** (map, set, bitset)

	Associative containers provide an ability for fast retrieval of data based on keys.
	`map` associates an arbitrary type T with the Key. 
	An associative container supports unique keys if it may contain at most one element for each key. `map`and `set` support unique keys.

	For `set`, the value type is the same as the key type. 
	For `map`, it is equal to `pair<const Key, T>`.

	![img](assets/associative_containers_schemas.png)

### Performance and optimisation

Sources:
- [FreeCodeCamp - Big 0 Complexity Chart](https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/)
- [Youtube Video on Classes of Complexity (FR)](https://www.youtube.com/watch?v=vzUK6YxkhB0)
- [HappyCoders - Big 0 Notation](https://www.happycoders.eu/algorithms/big-o-notation-time-complexity/)


The efficiency of algorithms is judged by the amount of resources they require, namely :
- time: duration of execution
- space: allocated hardware resources

Ainsi, le temps d'éxécution de l'algorithme constitue la ressource la plus significative qu'il faut quantifier : on parle alors de **complexité temporelle**. vous vous en doutez : moins la complexité est importante, plus l'algorithme est performant. Vu qu'un ordinateur plus puissant exécutera plus rapidement un programme, on va tenter de calculer la complexité d'une manière plus générale, en faisant une approximation du nombre d'opérations qui seront menées (coucou c'est la complexité asymptotique). 

Pour se faire, on utilise la notation Grand O. 

For instance, the ISO norm requires a complexity of :
1. 0(1) for the member function `size()` of the `stack` container.
2. O(n) for the member function `assign()` of the `vector`container.

<p align="middle" float="left">
<img src="https://i.ytimg.com/vi/47GRtdHOKMg/maxresdefault.jpg"  width="40%">
<img src="assets/bigo.png"  width="40%">
</p>
But what do all of these O's mean ?? :frowning: :open_mouth:

| Syntax   |      Name      | Definition | En supposant qu'une opération élémentaire prend 10 ns (nano sec) |
|:--------:|:--------------:|------------|---------|
| O(1) |  Constant | When your calculation is not dependent on the input size | O(1) = 10ns |
| O(log(n)) |    Logarithmic   | When the input size is reduced by half, maybe when iterating, handling recursion, or whatsoever | O(log(n)) = 20ns |
| O(n) | Linear |    When you have a single loop within your algorithm | O(n) = 500ns |
| O(nlog(n)) |  Quasilinear | in divide and conquer algos,  the problem is divided into sub problems(divide) that are solved separately and whose solutions are then combined (conquer). (ex: Quicksort, mergesort) | O(nlog(n)) = 850ns |
| O(n^k) |  Polynomial | When you have nested loops within your algorithm | O(n^k) = 25 µs (micro secondes) |
| O(2^n) |  Exponential | When the growth rate doubles with each addition to the input | O(2^n) = 130 jours ! |
| O(n!) |  Factorial | When the growth rate multiplies by itself | O(n!) = 10⁴8 ans !!! |

Exemple pour comprendre comment tout ca se calcule :

```pascal
// En pseudo code:

Algo de saisie:
Variables
	nom: Chaîne de caractères
Début
	Ecrire('Veuillez saisir votre nom: ')
	Lire(nom)
Fin
```
Ici, Ecrire et Lire comptent pour une opération, car ce sont deux instructions pouvant être réunies. Il n'y a donc qu'une seule opération dans l'algo => 0(1) (complexité constante)


Continuons :
```pascal
// En pseudo code:

Algo de saisie:
Variables
	nom, prenom, email: Chaîne de caractères
Début
	Ecrire('Veuillez saisir votre nom: ')
	Lire(nom)
	Ecrire('Veuillez saisir votre prenom: ')
	Lire(prenom)
	Ecrire('Veuillez saisir votre email: ')
	Lire(email)
Fin
```
Là, on a 3 opérations (Ecrire/Lire pour 1)nom, 2)prénom, 3)email). La complexité de cet algo est de 0(3). Comme ce chiffre ne changera jamais, et est donc CONSTANT, on dit que la complexité est de 0(1) (cf. la constance de l'algo!)

Dernier exemple :
```c

/* algo de recherche*/ 

int[4] tab = {1, 2, 3, 4};
int	   elem = n;

// Accéder à un élément de ce tableau :
for (size_t i = 0; i < 4; i++)
{
	if (int[i] == elem)
	{
		printf("The element was found!");
		break;
	}
}
printf("The element was not found...");
```
Dans le meilleur des scenarios, si la valeur n fournie par le user est le 1er élément du tableau, il n'y aura qu'une opération à faire. Mais si cet élément n'existe pas, on aura parcouru toute la tab_size + 1 ! On voit donc bien ici que la complexité de cet algo n'est pas constante. On dit alors que la complexité est ici de O(n) (complexité linéaire). n représente alors l'ordre de grandeur du nb d'opérations à exécuter, qui est équivalent au nombre d'itérations dans la boucle.

Si on a un algo qui, par exemple, demande de rechercher un élément au hasard dans deux tableaux de taille variable, la grandeur de la complexité sera égale à O(2n). Mais comme les facteurs multiplicatifs sont ignorés (coucou le 2), la complexité en Grand O est de O(n)!

Et ainsi de suite ! Si on a, pour x raisons, une situation où il y a deux boucles imbriquées, le nombre d'itérations de la grande boucle sera multiplié par le nombre d'itérations de la petit boucle. La complexité sera donc de O(n²) (complexité quadratique) (oui, elle ne fait pas partie du tableau, c'est que pour le kiff)


### Roadmap

#### (1) Stack

> The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
> The class template acts as a wrapper to the underlying container - only a specific set of functions is provided. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.

Page 507 of the ISO Norm (23.2.3.3 Template class stack)


#### (2) Some additional iterators and functions

#### (3) Vector

#### (4) Map

#### (5) Set (Bonus)


## Tips and tricks

### Resources

[Stack class template (in legacy to avoid missing post-98 implementations)](https://legacy.cplusplus.com/reference/stack/stack/)

### Tips

### Frequent errors