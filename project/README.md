# LoanCalculator

## Picth

    Nous allons créer les getters et setter pour `People
    - Mettre People dans son fichier `People.re`
    - Créer le fichier `.rei` associé
    - ajouter le module de Getter
    ```reason
      module Getter: {
        let getName: t => string;
        let getFirstname: t => string;
        let getAge: t => age;
        let getIncomeInInt: t => int;
        let getCredits: t => array(float);
      };
    ```
    - ajouter le module `Setter`

    ```reason
    module Setter: {
      let setName: (string, t) => t;
      let setFirstname: (string, t) => t;
      let setAge: (age, t) => t;
      let setIncome: (float, t) => t;
      let setCredits: (option(array(float)), t) => t;
      let removeCreditAt: (int, t) => t;
      let updateCreditAt: (int, float, t) => t;
    };
    ```
    - ajouter les implémentations


## Installation
```bash
yarn
```
## Development
Dans un terminal lancer le compilateur reason
```bash
yarn reason
```

Lancer NextJs
```bash
yarn
```

