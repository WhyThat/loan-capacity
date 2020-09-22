# LoanCalculator

## Picth

Dans cette étape,
on va vouloir créer une fonction `make` dans chaque module qui se chargera de créer un `type t` et on voudra s'assurer que seul le module puisse manipuler le type t;

- Créer un `type view` pour chaque module qui sera pour le moment le même que le `type t`
- Ajouter une signature à chaque module qui expose `t` comme un _phantom type_ ainsi que `view`
- Créer une fonction `make` pour chaque module qui retourne un `t`
- Créer une fonction `view` pour chaque module qui aura la signature suivant `t => view`

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


