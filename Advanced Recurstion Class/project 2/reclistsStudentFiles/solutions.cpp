#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}
list append(list p, list q){
    //expects p to be some list.
    if(is_null(p)){
        return q;
    }

    return cons(car(p),append(cdr(p),q));



}

/*is_lat takes a non-atomic (a list that is not an atom) list and returns true if the list is a
list (potentially empty) of atoms. (It can bomb out if p is an atom, or you may check for
errors and report them if you prefer.) For example
is_lat( (a b c) ) = true
is_lat( (a (b) c) ) = false
Remember: No while loops.*/
//this function checks to see if there are any lists in the list. if not return true.
bool is_lat(list p){
    //if p is a atom it bombs out
    if(is_atom(p)){
        std::cout<<"found an atom, expected a list"<<std::endl;
        return false;
    }
    //if no list is found in the list and p is null then return true
    if(is_null(p)){
        return true;
    }
    //otherwise if we find a list in the list then we return false.
    if(!is_atom(car(p))){
        return false;
    }
    // tail recursive call
    return is_lat(cdr(p));

}
/*p is an atom and q is an non-atomic list. member returns true if p appears anywhere in q.
(If p is not an atom or q is not a non-atomic list, the call is in error—you may detect this
or just bomb out.)*/
//p is one item, an atom and q is the list with nested lists
// remeber that you can use member as a helper function later on.
//the one acception when it comes to the no helper function for this assinment.
bool member(list p, list q){
    //check if we found p in q
    if(!is_atom(p)){
        std::cout<<"p isnt a atom"<<std::endl;
        return false;
    }
    // if we find a member of q who matches p then we return  true.
    if(eq(p,q)){
        return true;
    }

    //if we are at the end and reach a null return false.
    if(is_null(q)){
        return false;
    }
    // case that helps traverse the multi layer list in class however
    //unlike the example in class it uses the or operator as a way of
    // recursively calling both car and cdr so that if we find one value thats true
    // the final call back will be true. otherwise it will be false.
    if(!is_atom(q)){
        return (member(p,car(q)) || member(p,cdr(q)));
    }

    return false;


}
/*last returns the last element, ln, of a non-atomic, non-empty list. (Do this without using
reverse.) Note that last of (a b c) is c, not (c).*/
list last(list p){
    if (is_null(cdr(p))){
      return car(p);
    }
    return(last(cdr(p)));
}

/*list_pair takes two lists of atoms of the same length (you may check for an error if you
like—or just bomb out) and returns a list that consists of lists of two atoms each, which
are the corresponding atoms paired up. For example:
list_pair( (a b c),(d e f) ) = ( (a d) (b e) (c f) )*/
list list_pair(list p, list q){
    // so traverse the two lists together and cons each two items in ots own list which will then be added
    if(is_null(p)){
        return null();
    }
    if(is_null(p) && !is_null(q) ||!is_null(p) && is_null(q) ){
        std::cout<<" lists are not the same length. terminating"<<std::endl;
        exit(1);
    }
    // forst const combines the desired list to the larger list. its combinning the append of car p in a null list and car q in a null list
    //then the second parameter combines that with a recursive call that gets the next item to be added in list pair.
        return cons(append(cons(car(p),null()),cons(car(q),null())),list_pair(cdr(p),cdr(q)));


}
/*firsts takes as an argument a list whose elements are lists of atoms and returns a list
which contains the first element from each of the lists. For example:
firsts( ( (a b c) (d e f) (c d b a) ) ) = ( a d c )*/
list firsts(list p){
    // if we find a atom return it
    if(is_atom(p)){
        return p;
    }
    // if we find the end of the list return null
    if(is_null(p)) {
        return null();
    }

    // without his check it would fill the list so that it matches the one input.
    // checks to see if the next item down is a atom and if the item next to it is also a atom
    // if so it recursive calls without calling cdr  as to not pick up unwanted input.
    if(is_atom(car(p)) && is_atom(car(cdr(p)))){
        return firsts(car(p));
    }
    // otherwise tail recurse to the next cdr in the list.
    return cons(firsts(car(p)),firsts(cdr (p)));


}

/*
list flat(list p){
    flat takes a non-atomic list and returns a list which is the original list with the parenthesis
    removed (except for the outer set). For the lists in (3) of the definition, flat yields
            (a b)
            (c)
            (a b c d e)
            (a b c b)
*/
list flat(list p) {
    // if we find a atom return it
    if (is_atom(p)) {
        return p;
    }
    // if we find the end of the list return null
    if (is_null(p)) {
        return null();
    }
    // if is_atom(car(p)) then append p and null()?


    // otherwise tail recurse to the next cdr in the list.

    if (!is_atom(cdr(p))&& !is_atom(car(p))) {
    return append(append(flat(car(p)), null()), flat(cdr(p)));
    }
    return cons(flat(car(p)),flat(cdr (p)));


}

/*two_the_same takes two non-atomic recursive lists and returns true if p and q contain at
least one atom in common*/
bool two_the_same(list p, list q){
    // plan, use member to check each atom in one list ans see if its a member in the other list.
    //if true then return true otherwise return false. also traverse recursive like other functions
    if(is_null(p)) {
        return false;
    }
    if(is_atom(car(p))){
        if(member(car(p),q)){
            return true;
        }else{
            return two_the_same(cdr (p),q);
        }
    }
    // if we find the end of the list return null
    // car being called can cause errors. need to check if car(p) is safe.
        return (two_the_same(car(p),q)||two_the_same(cdr (p),q));

}

/*equal takes two arbitrary recursive lists and determines if they are identical, that is the
parentheses are all in the same place and the atoms agree as to place and name. This is
an extension of eq.*/
bool equal(list p, list q){
    //if we hit the end of p and end of q return true
    if(is_null(p)&& is_null(q)) {
        return true;
    }
    // if ether p or q is null but the other is nut null then we know that the lists are not the same.
    if(is_null(p) && !is_null(q) || !is_null(p) && is_null(q)){
        return false;
    }
    //if we find an atom in both also check to see ifthere equal. if so return true
    if(is_atom(p) && is_atom(q) && eq(p,q)){
        return true;
    }
    //if we find two atoms but they are not the same, return false
    if(is_atom(p) && is_atom(q) && !eq(p,q)){
        return false;
    }
    //if p or q is an atom but the other isn't then return false
    if(is_atom(p) && !is_atom(q) || !is_atom(p) && is_atom(q)){
        return false;
    }
    // and logic operator. if one instance of p or q is found to be false, the whole thing will return false.
    // may need a catch case if the lists are drastically different. cdr and car may call when it is a atom
    return (equal(cdr(p),cdr(q)) && equal(car(p),car(q)));



}
/*This function takes a recursive list and returns its mirror image. It is the extension of
reverse that reverses the list and each sub-list, recursively, unto the nth generation.*/
list total_reverse(list p){
    // currently this is the shallow reverse from the lab.
    if(is_null(p)){
        return null();
    }
    //return append(total_reverse(cdr(p)),cons((car(p)),null()));
    //potentially we need to check if car p is an atom. if not then we can car down until it is and reverse? also need to be reversing in above layers as well.
    if(is_atom(car(p))){
        return append(total_reverse(cdr(p)),cons((car(p)),null()));
    }

        return append(total_reverse(cdr(p)),cons(total_reverse(car(p)),null()));


}

/*shape takes a non-atomic recursive list and returns a recursive list that consists of only
the parentheses in the original.*/
list shape(list p){

    if(is_null(p)){
        return null();
    }
    if(!is_null(car(p)) && is_atom(car(p))){
        return append(null(),shape(cdr (p)));
    }

    // if it finds a atom it stops checking
    return cons(shape(car(p)),shape(cdr (p)));
}
/*p and q are lists of atoms with no atom appearing twice in p and no atom appearing twice
in q. p and q represent sets. intersection forms their intersection. (The empty list
represents the empty set.)*/
list intersection(list p, list q){
    // if we find null of p return.
    if(is_null(p)){
        return null();
    }
    // if car(p) is an atom and its also a member in q then cons that atom with recursive call to this function
    if(is_atom(car(p)) && member(car(p),q)){
        return cons(car(p),intersection(cdr(p),q));
    }

    // otherwise return recursive call cdr p
    return intersection(cdr(p),q);


}
/*list_union forms the set which is their union—remember if p and q have an atom in
common then this atom should only appear once in the union.*/
//first fill list with atoms of q checking if they are already an element in p. if they are then dont add them.
// second fill the list with all atoms in p
list list_union(list p, list q){

    // if we reach the end of q return null but only if p is also null.
    if(is_null(q) && is_null(p)){
        return null();
    }
    // if p is null then we want to fill the list with q
    if(is_null(p) && !is_null(q)){
        return cons(car(q),list_union(p,cdr(q)));
    }
    // if p and q are not empty then we recurse through p
    //checking if car(p) is a atom and if its a member of q
    // if it is a member of q we ignore it and cdr to the next p
    if(member(car(p),q)){
        return list_union(cdr(p),q);
    }
    return(cons(car(p), list_union(cdr(p),q)));

}

