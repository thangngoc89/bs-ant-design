let from_bool = Js.Boolean.to_js_boolean;

[@bs.set_index] external _set: (Js.t({..}), string, 'a) => unit = "";

let addAnyProp = (propname: string, prop: option('a), acc) => switch prop {
  | Some(a) => {_set(acc,propname,a); acc}
  | None => acc
};

[@bs.deriving jsConverter]
type breakpoint = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xxl
  | [@bs.as "xxl"] `Xxl
];