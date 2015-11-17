# Paper Summary
## i. 

## ii. Keywords

1. **Product Line Engineerin :** It can be defined as a development paradigm that addresses reuse by differentiating between two kinds of development process, namely:
	1. Domain Engineering: In this process the domain artifacts of the product are defined and developed.
	2. Application Engineering: In this process marked specific products are derived from above constructed domain artifacts according to the needs and expectations from the product.

2. **Model Checking :** "Model checking of domain artifacts means to verify that every possible product that can be derived from a domain artifact fulfills the specified properties." This essentially means that model checking is the method by which we check all the possible behaviours (possible reuses) of a domain artifact so that no fault is encountered when a domain artifact is reused.

3. **Variability, :** The variability model is interpreted as a set of variants "V" where each variant "vi" is represented by a boolean variable. The variability and constraints dependencies of the variability model are translated into Boolean expressions over the variables of the variation points and variants.

4. **Domain Artifact Verification  :** This may be defined as the process of ensuring that any product derived from a domain artifact fulfills the required properties from that product.


## iii. Artifacts

1. **Motivation:** Model checking as a formal verification technique has received little attention in product line engineering. For verifying domain artifacts, model checking approaches from single system engineering are only of limited use. In this paper the authors explain how since existing model checking approaches do not incorporate product line variability, they are of limited use for domain artifact verification. In the paper they go on to present an extended model checking approach which takes into account product variability when verifying domain artifacts.

2. **Hypothesis:** The authors thus hypothise that with the ability to add product variability to existing methods the authors can extend model varification to be a more comprehensive tool for domain artifact verifications. It is intuitive that a model verification method which takes into account the possibility of the mutation of artifact properties will be able to more comprehensively test the said artifact.

3. **Related Work:** Classen et al. describe the general problem of determining whether a set of features can be composed as a problem called "safe composition"; Delaware introduced Lightweight Feature Java(LFJ) to formalize feature-based product lines. Liu proposed an incremental and compositional model-checking technique for performing sequential compositions of different features of a product line. Some of the important historical refferences for this paper are as follows:
	1. Delaware B.; Cook, W.R.; Batory D.: Fitting the pieces together: A Machine-Checked Model of Safe Composition. In Proc. of ESEC-FSE  ́09, 2009
	2. Grumberg, O.; Veith, H.: 25 Years of Model Checking. LNCS Vol. 5000, Springer, 2008
	3. Larsen, K.; Nyman, U.; Wąsowski, A.: Modal I/O Automata for Interface and Product Line Theories. In Proc. of ESOP, 2007, pp. 64-79.
	
    
4. **Data:** Two models have been used in this eperiment: The first consists of five variable I/O-automata and an orthogonal variability model which specifies six variation points and 14 variants. Overall 189 products can be derived from this specification. The second one is much larger. It is a realistic specification. It consists of six variable I/O-automata and the orthogonal variability model of the specification consists of ten variation points and 46 variants and allows the derivation of 237 different products. The product automaton of the specification consists of more than 68.000 states and 174.000 transitions.
    

## iv. Possible Improvements
1. The authors have introduced the concept of smart models, but they have not given any baseline results to verify this claim against. A more comprehensive understanding of the improvements could be garnered a more thorough coverage of baseline results was also porvided.

2. The results also fail to display consistancy, or performance for different sets. Limited experiments also prevent the user from garnering a more thorough understanding of whether this method is comprehensive and encompasses all possible use cases and if so provides a better throughput than other methods more often than not.

3. As mentioned in the above point, the paper fails to mention or display the preformance metrics in comparison to baseline metrics, as such thus the paper also fails to mention any limitations that this method may have that may be solved in future work.

3.

