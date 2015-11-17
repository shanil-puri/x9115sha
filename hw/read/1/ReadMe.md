# Paper Summary
## i. Sven Apel, Hendrik Speidel, Philipp Wendler, Alexander von Rhein, Dirk Beyer. 2011. Detection of Feature Interactions using Feature-Aware Verification. Proceeding
ASE '11 Proceedings of the 2011 26th IEEE/ACM International Conference on Automated Software Engineering

## ii. Keywords


1. **Software Product Line :** Software Product line is defined as a family of software products that share a certain set of core features but at the same time differ in other core features so as to be classified as seperate entities.

2. **Feature :** A feature is a core behaviour of the product that is visible to the end user of the product. This feature is considered to be the core deliverable expected out of a product and is of importance to stakeholders of the software product.

3. **Feature Interaction :** Feature interaction is essentially defined as the behaviour that a set of software products exhibit when interacting together. This behaviour should be non-existant if any of the interacting products are absent. Thus this unique resultant behaviour seen by the interaction of multiple software products is known as Feature Interaction

4. **Feature-aware verification :** The approach of identifying the presence or absence of the above mentioned "feature interaction" in a software system has been reffered to as Feature-aware verification in this paper. This is also the premise and the primary contribution of this paper.

5. **Product-line–verification :** Technique for verifying that all products of a product line satify the expectations from them.


## iii. Artifacts

1. **Aim:** The major aim of the paper is to explore how product line verification techniques can be used to automatically detect feature interaction. It aims to tackle two main challenges in feature interaction detection, namely:
	1. "The detection of feature interaction based on specifications that do not have global feature system knowledge" (Related Work 3.1). This essentially means that for feature interaction detection the particular specification should not need to be aware of all the features of the system as Modularity is a desirable trait in product development.
	2. Detect Feature Interaction without the need for generating and checking all individual products. Generating all possible combinations of features in a real time product may lead to the generation of large number of combinations, essentially rendering this approach non-feasible.

2. **Hypothesis:** The authors suggest and demonstrate a method that can detect the absence or presence of Feature Interation. They have named their approach "Feature Aware Interaction". They have essentially provided a two step solution to the challenges presented above:
	1. The authors provide a "specification language" which can be used to define the temporal (time related) features of a product in seperate and composable units.
	2. The seccond step the authors use is that of "Variability Encoding" (Related Work 3.2) to verify a complete product line in a single run while ensuring all prossible product interactions are verified to not have critical feature interactions. 

3. **Related Work:**
    
    1. R. Hall. Fundamental Nonmodularity in Electronic Mail. Automated Software Engineering, 12(1):41–79, 2005
    
    2. H. Post and C. Sinz. Configuration Lifting: Verification meets Software Configuration. In Proc. ASE, pages 347–350. IEEE, 2008
    
    3. S. Apel, C. Lengauer, B. Möller, and C. Kästner. An Algebraic Foundation  for  Automatic  Feature-Based  Program  Synthesis. Science of Computer Programming, 75(11):1022–1047, 2010.

    4. S. Apel, C. Kästner, and C. Lengauer. FeatureHouse: Language-Independent, Automated Software Composition. In Proc. ICSE,  pages 221–231. IEEE, 2009.

4. **Commentary:**

    Baseline results for this paper have been specified in results obtained from making a case study of Hall's Email Client(Related work 3.1). The results for the same maybe summarized as follows:
    
    1. Implementation: SPLVERIFIER is a test suite developed for this case study using other existing tools and other tools developed for this case study for the purpose of feature aware verification. FEATUREHOUSE has been used for composition and variability encoding. Model checking has been carried out using CPAChecker (D. Beyer and M. E. Keremoglu. CPACHECKER: A tool for configurable software verification. In Proc. CAV, LNCS 6806, pages 184–190. Springer, 2011). 
    
    2. The E-Mail Client Case Study: For this part of the study the authors have used Hall's Email Client (as described in Related Work 3.1). The email client gives rise to 10 features with 27 feature interactions. Authors developed several automata for every relevant feature, based on the work of Hall (Related Work 3.1)
    
    3. Experiments: The authors generated all of the 40 products for Hall's Email product line and checked it using CPAChecker.  It turned out that with feature-aware  verification, the authors were able to detect all feature interactions of the e-mail client based on the feature-local specifications of the input features.
    

## iv. Possible Improvements

1. The current implementation does not work with distibuted product systems. This can be added to make this tool more comprehensive.
2. Automation of seperation of features into seperate composable units. At present a user needs to use the provided specification language for feature definition. Machine learning techniques may be used to make this process autonomous in either supervised or unsupervised learning environments.
3. Comprehensive results against multiple different kinds of product lines have not been given and the conclusions are based on the results from the investigation of a single product line. A more comprehensive experimental setup would be able to further demonstrate the effectiveness and efficiency of their methods.