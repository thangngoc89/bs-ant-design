[@bs.module] external icon: ReasonReact.reactClass = "antd/lib/icon";

[%bs.raw {|require("antd/lib/icon/style")|}];

[@bs.deriving jsConverter]
type theme = [ | `filled | `outlined | `twoTone];

[@bs.deriving abstract]
type jsProps = {
  [@bs.optional]
  tabIndex: int,
  [@bs.optional] [@bs.as "type"]
  type_: string,
  [@bs.optional]
  className: string,
  [@bs.optional]
  theme: string,
  [@bs.optional]
  title: string,
  [@bs.optional]
  onClick: ReactEvent.Mouse.t => unit,
  [@bs.optional]
  component: ReasonReact.reactElement,
  [@bs.optional]
  twoToneColor: string,
  [@bs.optional]
  viewBox: string,
  [@bs.optional]
  spin: bool,
  [@bs.optional]
  rotate: int,
  [@bs.optional]
  style: ReactDOMRe.Style.t,
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  role: string,
};

let make =
    (
      ~tabIndex=?,
      ~type_=?,
      ~className=?,
      ~theme=?,
      ~title=?,
      ~onClick=?,
      ~component=?,
      ~twoToneColor=?,
      ~viewBox=?,
      ~spin=?,
      ~rotate=?,
      ~style=?,
      ~prefixCls=?,
      ~role=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=icon,
    ~props=
      jsProps(
        ~tabIndex?,
        ~type_?,
        ~className?,
        ~theme=?Js.Option.map((. b) => themeToJs(b), theme),
        ~title?,
        ~onClick?,
        ~component?,
        ~twoToneColor?,
        ~viewBox?,
        ~spin?,
        ~rotate?,
        ~style?,
        ~prefixCls?,
        ~role?,
        (),
      ),
    children,
  );