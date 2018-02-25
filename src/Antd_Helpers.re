let from_bool = Js.Boolean.to_js_boolean;

type eitherProp('a,'b) = 
  | SimpleProp('a)
  | ObjectProp('b);

/* this feels sketchy */
[@bs.set_index] external _set: ('o, string, 'a) => unit = "";

let addEitherProp = (propname: string, prop, acc) => switch prop {
  | Some(SimpleProp(a)) => {
    _set(acc,propname,a);
    acc
  }
  | Some(ObjectProp(b)) => {
    _set(acc,propname,b);
    acc
  }
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