open Antd_Helpers;

[@bs.module "antd/lib/radio"]
external reactClass : ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/radio/style")|}];

[@bs.obj]
external makeProps :
  (
    ~autoFocus: Js.boolean=?,
    ~checked: Js.boolean=?,
    ~defaultChecked: Js.boolean=?,
    ~disabled: Js.boolean=?,
    ~value: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~autoFocus=?,
      ~checked=?,
      ~defaultChecked=?,
      ~disabled=?,
      ~value=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~autoFocus=?Js.Option.map([@bs] (b => from_bool(b)), autoFocus),
        ~checked=?Js.Option.map([@bs] (b => from_bool(b)), checked),
        ~defaultChecked=?
          Js.Option.map([@bs] (b => from_bool(b)), defaultChecked),
        ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
        ~value?,
        ~id?,
        ~className?,
        ~style?,
        ()
      ),
    children
  );

module Group = {
  [@bs.module "antd/lib/radio"]
  external reactClass : ReasonReact.reactClass = "Group";
  [@bs.deriving jsConverter]
  type size = [ | `default | `small | `large];
  [@bs.obj]
  external makeProps :
    (
      ~defaultValue: string,
      ~disabled: Js.boolean=?,
      ~name: string=?,
      /* @todo: type me */
      ~options: 'a=?,
      ~size: string=?,
      ~value: string,
      ~onChange: ReactEventRe.Form.t => unit,
      ~id: string=?,
      ~className: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~defaultValue,
        ~disabled=?,
        ~name=?,
        ~options=?,
        ~size=?,
        ~value,
        ~onChange,
        ~id=?,
        ~className=?,
        ~style=?,
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~defaultValue,
          ~disabled=?Js.Option.map([@bs] (b => from_bool(b)), disabled),
          ~name?,
          ~options?,
          ~size=?Js.Option.map([@bs] (b => sizeToJs(b)), size),
          ~value,
          ~onChange,
          ~id?,
          ~className?,
          ~style?,
          ()
        ),
      children
    );
};