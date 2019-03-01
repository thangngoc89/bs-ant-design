[@bs.module] external reactClass: ReasonReact.reactClass = "antd/lib/checkbox";

[%bs.raw {|require("antd/lib/checkbox/style")|}];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~className: string=?,
    ~defaultChecked: bool=?,
    ~checked: bool=?,
    ~style: ReactDOMRe.Style.t=?,
    ~disabled: bool=?,
    ~onChange: 'a => unit=?,
    ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
    ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
    ~onKeyPress: ReactEvent.Keyboard.t => unit=?,
    ~onKeyDown: ReactEvent.Keyboard.t => unit=?,
    ~value: unit=?,
    ~tabIndex: int=?,
    ~name: string=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~className=?,
      ~defaultChecked=?,
      ~checked=?,
      ~style=?,
      ~disabled=?,
      ~onChange=?,
      ~onMouseEnter=?,
      ~onMouseLeave=?,
      ~onKeyPress=?,
      ~onKeyDown=?,
      ~value=?,
      ~tabIndex=?,
      ~name=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~prefixCls?,
        ~className?,
        ~defaultChecked?,
        ~checked?,
        ~style?,
        ~disabled?,
        ~onChange?,
        ~onMouseEnter?,
        ~onMouseLeave?,
        ~onKeyPress?,
        ~onKeyDown?,
        ~value?,
        ~tabIndex?,
        ~name?,
        (),
      ),
    children,
  );

module Group = {
  [@bs.module "antd/lib/checkbox"]
  external reactClass: ReasonReact.reactClass = "Group";
  [@bs.deriving jsConverter]
  type size = [ | `default | `small | `large];
  [@bs.obj]
  external makeProps:
    (
      ~prefCls: string=?,
      ~className: string=?,
      /* options?: Array<CheckboxOptionType | string>; */
      ~options: array(string)=?,
      ~disabled: bool=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (~prefCls=?, ~className=?, ~options=?, ~disabled=?, ~style=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(~prefCls?, ~className?, ~options?, ~disabled?, ~style?, ()),
      children,
    );
};