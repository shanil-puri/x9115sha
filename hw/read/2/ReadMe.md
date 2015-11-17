# Paper Summary
## i. Apel, Sven, Christian Lengauer, Bernhard Möller, and Christian Kästner. "An algebraic foundation for automatic feature-based program synthesis." Science of Computer Programming 75, no. 11 (2010): 1022-1047.

## ii. Keywords


1. **Feature-oriented software development(FOSD) :** This can be defined as a programming paradigm which provides the tools and guidelines to building variable, customizable and extensible software.

2. **Software feature :** A software feature is the basic abstraction of FOSD. A software feature represents the requirement of a stakeholder in a software and is essentially the implementation of this requirement. Features are used to differentiate between different programs or software systems.

3. **Feature composition :** This can be defined as the process of composing the code to essentially implement the features as defined by the stakeholders. This step thus entails the actualy working implementation of the above mentioned feature.

4. **Feature Algebra :** Feature algebra serves a four fold purpose, namely:
    1. Abstraction: Used for abstraction from details related to Programming languages and environments in FOSD.
    2. Alternative design decision: Reflects variants and alternatives in concrete programming language mechanisms.
    3. Can be used for type checking and interaction analysis.
    4. To provide and architectural view of the software system.
    
    This term has been introduced in this paper as original work.


## iii. Artifacts

1. **Motivation:** The author of this paper tried to build an algebra system for definition of programming systems. They introduced the concept of feature algebra which served the four fold purpose of: Abstraction (Used for abstraction from details related to Programming languages and environments in FOSD), Alternative design decision (Reflects variants and alternatives in concrete programming language mechanisms), Can be used for type checking and interaction analysis and To provide and architectural view of the software system. The algebra thus serves to provide a formalism to express the necessary abstraction from the implementation level, as well as the reasoning about software architectures.

2. **Hypothesis:** The authors present a novel idea of feature algebra that captures the key ideas of feature orientation and that provides a common ground for current and future research. The authors propose that their novel "Feature Algebra" framework is meant to serve as basis for development of technology of automatic feature based program synthesis and will for the basis for architectural metaprogramming.

3. **Related Work:**
gDeep is a calculus for features and feature composition independently of a particular language. HOFNER et al. have developed an algebra for expressing software and hardware variabilities in form of features.

Also, features are implemented not only by source code. Several tools support the feature-based composition of non-source code artifacts. 
    
4. **Checklist:** The main purpose for this paper is to introduce an algebraic system to express the operations for feature model. This algebric system has been termed as "Feature Algebra" by the authors and is essentially used to abstract programming concepts and for use as a concrete representation of features in programming language specific terms. Consequently, in this paper, the author puts forth his work in the following order:
    1. Defining the feature model;
    
    2. Defining the expression system for them (Feature Algebra); 
    
    3. Defining some basic operations: composition, introductions, modifications, etc.; 
    
    4. Finally all the above steps are combined to form the quark model.
    

## iv. Possible Improvements
1. In this paper the quark model has been provided as the combination/conclusion of the paper. I believe the visualization of the Quark model with the other operators would be a better representation of the idea.

2. Function Algebra defined in the paper gets its basis from linear algebra and as such the author would better serve the reader comparing examples of operations to similar operations in Linear algebra thus providing a more thorough understanding of the concepts of the operations.

3. This paper uses the Java package example is used to illustrate the algebraic foundation. However feature model is widely used in software product development. A more thorough experimental setup with more examples with some other frequently used languages would serve to give a user a better understanding of the paper.

