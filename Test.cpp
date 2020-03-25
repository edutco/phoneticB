#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace std;
#include <string>
using namespace phonetic;

// Id of collaborators 208825539 207950577

TEST_CASE("Test replacement of p, f and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find("hello my friends", "  hello")==string ("hello")); // spaces check
}

TEST_CASE("Test replacement of lower-case and upper-case") {
   string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
}
/** all other possible permutations*/
/**c-k-q    b-p-f   d-t     o-u     v-w     g-j     s-z     i-y     and of course lower case and upper case changes*/
TEST_CASE("Test replacement of any possibility") {
    string text = "qhanJe yUur Dhuoghts anT you change yuOr vorlt";
    CHECK(find(text, "Change") == string("qhanJe")); //c-q, g-j
    CHECK(find(text, "your") == string("yUur")); //o-u
    CHECK(find(text, "thoughts") == string("Dhuoghts")); //t-d 
    CHECK(find(text, "and") == string("anT"));//t-d
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "change") == string("qhanJe"));//c-q g-j
    CHECK(find(text, "world") == string("vorlt")); //w-v d-t
    
    text = "dhUse Vho realize DhEIr Polly arE not true BoolZ";
    CHECK(find(text, "Those") == string("dhUse"));
    CHECK(find(text, "who") == string("Vho"));
    CHECK(find(text, "realize") == string("realize"));
    CHECK(find(text, "their") == string("DhEIr"));
    CHECK(find(text, "folly") == string("Polly"));
    CHECK(find(text, "are") == string("arE"));
    CHECK(find(text, "not") == string("not"));
    CHECK(find(text, "true") == string("true"));
    CHECK(find(text, "fools") == string("BoolZ"));

    text = "life is too IMPORTANT DU PE TAken ZerYOUsly";
    CHECK(find(text, "Life") == string("life"));
    CHECK(find(text, "Yz") == string("is"));
    CHECK(find(text, "tUo") == string("too"));
    CHECK(find(text, "important") == string("IMPORTANT"));
    CHECK(find(text, "to") == string("DU"));
    CHECK(find(text, "be") == string("PE"));
    CHECK(find(text, "taken") == string("TAken"));
    CHECK(find(text, "seriously") == string("ZerYOUsly"));
   
    text = "ID aLWais zeems impossible OnTYL it IS Tone";
    CHECK(find(text, "It") == string("ID"));
    CHECK(find(text, "always") == string("aLWais"));
    CHECK(find(text, "seems") == string("zeems"));
    CHECK(find(text, "impossible") == string("impossible"));
    CHECK(find(text, "until") == string("OnTYL"));
    CHECK(find(text, "it") == string("ID"));
    CHECK(find(text, "is") == string("IS"));
    CHECK(find(text, "done") == string("Tone"));

    text = "ceep iour eyes on the stars and your feet on the ground";
    CHECK(find(text, "Keep") == string("ceep")); //c-k
    CHECK(find(text, "your") == string("iour"));
    CHECK(find(text, "eyes") == string("eyes"));
    CHECK(find(text, "on") == string("on"));
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "stars") == string("stars"));
    CHECK(find(text, "and") == string("and"));
    CHECK(find(text, "feet") == string("feet"));
    CHECK(find(text, "on") == string("on"));
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "ground") == string("ground"));
   
    text = "Life Is A Kuestyon ant hUv ve live Id iS UOr answer";
    CHECK(find(text, "Life") == string("Life"));
    CHECK(find(text, "is") == string("Is"));
    CHECK(find(text, "a") == string("A"));
    CHECK(find(text, "question") == string("Kuestyon"));
    CHECK(find(text, "and") == string("ant"));
    CHECK(find(text, "how") == string("hUv"));
    CHECK(find(text, "we") == string("ve"));
    CHECK(find(text, "it") == string("Id"));
    CHECK(find(text, "is") == string("Is"));
    CHECK(find(text, "our") == string("UOr"));
    CHECK(find(text, "answer") == string("answer"));
   
    text = "difficult ant MEANYnjPol viLL aLVays frinj mure satisfaction dhan eaZi ant meaningless";
    CHECK(find(text, "Difficult") == string("difficult"));
    CHECK(find(text, "and") == string("ant"));
    CHECK(find(text, "meaningful") == string("MEANYnjPol"));
    CHECK(find(text, "will") == string("viLL"));
    CHECK(find(text, "always") == string("aLVays"));
    CHECK(find(text, "bring") == string("frinj"));
    CHECK(find(text, "more") == string("mure"));
    CHECK(find(text, "satisfaction") == string("satisfaction"));
    CHECK(find(text, "than") == string("dhan"));
    CHECK(find(text, "easy") == string("eaZi"));
    CHECK(find(text, "and") == string("ant"));
    CHECK(find(text, "meaningless") == string("meaningless"));
   
    text = "Id ys petter to be hadet pur VhaT you are than do fe lOved bor whaD iuo are nUt";
    CHECK(find(text, "it") == string("Id"));
    CHECK(find(text, "is") == string("ys"));
    CHECK(find(text, "better") == string("petter"));
    CHECK(find(text, "to") == string("to"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "hated") == string("hadet"));
    CHECK(find(text, "for") == string("pur"));
    CHECK(find(text, "what") == string("VhaT"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "are") == string("are"));
    CHECK(find(text, "than") == string("than"));
    CHECK(find(text, "to") == string("to"));
    CHECK(find(text, "be") == string("be"));
    CHECK(find(text, "loved") == string("lOved"));
    CHECK(find(text, "for") == string("pur"));
    CHECK(find(text, "what") == string("VhaT"));
    CHECK(find(text, "you") == string("you"));
    CHECK(find(text, "are") == string("are"));
    CHECK(find(text, "not") == string("nUt"));
   
    text =  "YoU Unly lYve ONCE but if YUO To Yt ryghd is enUugh";
    CHECK(find(text, "you") == string("YoU"));
    CHECK(find(text, "only") == string("Unly"));
    CHECK(find(text, "live") == string("lYve"));
    CHECK(find(text, "once") == string("ONCE"));
    CHECK(find(text, "but") == string("but"));
    CHECK(find(text, "if") == string("if"));
    CHECK(find(text, "you") == string("YoU"));
    CHECK(find(text, "do") == string("To"));
    CHECK(find(text, "it") == string("Yt"));
    CHECK(find(text, "right") == string("ryghd"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "enough") == string("enUugh"));
}

TEST_CASE("Test of Incorrect inputs") {
    string text =  "You only live once but if you do it right once is enough";
   
    
    try {
        cout << phonetic::find(text, "onceo") << endl;   // should throw an exception , invallid character
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl;
    }
    try {
        cout << phonetic::find(text, "happ") << endl;   // should throw an exception - "happ" is not a full word in the sentence
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'happ' in the text"
    }
    try {
        cout << phonetic::find(text, "yo") << endl;   // should throw an exception - "yo" is not a full word in the sentence
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'yo' in the text"
    }
    try {
        cout << phonetic::find(text, "onry") << endl;   // should throw an exception
    } catch (exception & ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'onry' in the text"
    }
    try {
        cout << phonetic::find(text, "lvee") << endl;   // should throw an exception
    } catch (exception & ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'lvee' in the text"
    }
    try {
        cout << phonetic::find(text, "umqe") << endl;   // should throw an exception
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'umqe' in the text"
    }
    try {
        cout << phonetic::find(text, "BQT") << endl;   // should throw an exception
    } catch (exception &ex) {
        cout << "   caught exception: " << ex.what() << endl;  // should print "Did not find the word 'BQT' in the text"
    }
}
